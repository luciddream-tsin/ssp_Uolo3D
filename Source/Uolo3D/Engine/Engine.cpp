//
// Created by Administrator on 2022/6/13.
//

#include "Engine.h"
#include "Core/Context.h"
#include "IO/Log.h"

namespace Uolo3D {
    Engine::Engine(Context *context) : Object(context), exiting_(false){
        //TODO:  检测开始关闭Log时, 使用UOLO3D_INFO等是否合法

        context_->RegisterSubsystem(new Log(context_));

    }

    bool Engine::Initialize(unordered_map<string, ep_type> engineParameters) {
        //TODO: when initialize failed, set exiting_ = true and return
        int i = engineParameters[EP_LOG_LEVEL].int_;

        context_->GetSubsystem<Log>()->SetLogLevel(engineParameters[EP_LOG_LEVEL].int_);



        return false;

    }

    void Engine::RunFrame() {

        SendEvent(E_ENDFRAME);
    }

    bool Engine::IsExiting() {
        return exiting_;
    }
}