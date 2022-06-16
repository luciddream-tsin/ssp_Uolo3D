//
// Created by Administrator on 2022/6/13.
//

#include "Engine.h"
#include "Core/Context.h"
#include "IO/Log.h"
#include "Graphics/Graphics.h"

namespace Uolo3D {
    Engine::Engine(Context *context) : Object(context), exiting_(false){
        //TODO:  检测开始关闭Log时, 使用UOLO3D_INFO等是否合法

        context_->RegisterSubsystem(new Log(context_));
    }

    bool Engine::Initialize(unordered_map<string, params_union> engineParameters) {
        //TODO: when initialize failed, set exiting_ = true and return
        context_->GetSubsystem<Log>()->SetLogLevel(engineParameters[EP_LOG_LEVEL].int_);

        GAPI gapi = engineParameters[EP_OPENGL].bool_ ? GAPI_OpenGL : GAPI_Aurora;
        Graphics *graphics = (Graphics *)context_->RegisterSubsystem(new Graphics(context_, gapi));

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

        SendEvent(E_ENDFRAME);
    }

    bool Engine::IsExiting() {
        return exiting_;
    }
}