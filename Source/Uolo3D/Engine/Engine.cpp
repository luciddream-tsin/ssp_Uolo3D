//
// Created by Administrator on 2022/6/13.
//

#include "Engine.h"
#include "Core/Context.h"
#include "IO/Log.h"
#include "Graphics/Graphics.h"
#include "Graphics/Renderer.h"
#include "Core/Timer.h"

namespace Uolo3D {
    Engine::Engine(Context *context) : Object(context), exiting_(false), maxFPS_(2), frameTimer_(){
        //TODO:  检测开始关闭Log时, 使用UOLO3D_INFO等是否合法

        context_->RegisterSubsystem(new Log(context_));
        context_->RegisterSubsystem(new Time(context_));
    }

    bool Engine::Initialize(unordered_map<string, params_union> engineParameters) {
        //TODO: when initialize failed, set exiting_ = true and return
        context_->GetSubsystem<Log>()->SetLogLevel(engineParameters[EP_LOG_LEVEL].int_);

        GAPI gapi = engineParameters[EP_OPENGL].bool_ ? GAPI_OpenGL : GAPI_Aurora;
        Graphics *graphics = (Graphics *)context_->RegisterSubsystem(new Graphics(context_, gapi));
        Renderer *renderer = (Renderer *)context_->RegisterSubsystem(new Renderer(context_));

        if (!graphics){
            UOLO3D_ERROE("Graphics Is NULL");
            return false;
        }

        // add renderer later ...
        // renderer code...

        bool resultSetScreenMode = graphics->SetScreenMode(engineParameters);
        if (!resultSetScreenMode) return false;

        return true;

    }

    void Engine::RunFrame() {

        Time *time = context_->GetSubsystem<Time>();

        time->BeginFrame();

        Update();
        Render();
        FrameLimit();

        time->EndFrame();

        //SendEvent(E_ENDFRAME);
    }

    void Engine::Update() {
        UOLO3D_LOG_("Engine::Update()");
    }

    void Engine::Render() {
        UOLO3D_LOG_("Engine::Render()");
        context_->GetSubsystem<Graphics>()->BeginFrame();
        context_->GetSubsystem<Renderer>()->Update();
        context_->GetSubsystem<Graphics>()->EndFrame();
    }

    void Engine::FrameLimit() {
        long long maxUSPF = 1000000LL / maxFPS_; //us per frame, USPF

        while(maxUSPF >= frameTimer_.GetUSec(false)){

            // 如果帧率太小, 直接使用线程睡眠, 而不是在while里空轮
            // Note: 当第一次进入while时, trialSleepTime 最大, 如果第一次都没有sleep 以后不可能sleep
            long long trialSleepTime = maxUSPF - frameTimer_.GetUSec(false);
            if (trialSleepTime >= 1000LL){
                UOLO3D_LOG_("sleep");
                auto sleepTime = (unsigned)(trialSleepTime / 1000LL);
                Time::Sleep(sleepTime);
            }
        }

        frameTimer_.Reset();
        UOLO3D_LOG_("end: " + to_string(frameTimer_.GetUSec(false)));
    }

    bool Engine::IsExiting() {
        return exiting_;
    }
}