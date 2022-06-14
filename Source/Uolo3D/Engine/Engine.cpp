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

    void Engine::RunFrame() {

        SendEvent(E_ENDFRAME);
    }

    bool Engine::IsExiting() {
        return exiting_;
    }
}