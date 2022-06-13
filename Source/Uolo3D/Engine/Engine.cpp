//
// Created by Administrator on 2022/6/13.
//

#include "Engine.h"
#include "Core/Context.h"
#include "iostream"
#include "IO/Log.h"


namespace Uolo3D {
    Engine::Engine(Context *context) : Object(context), exiting_(false){
        //TODO: 添加子系统, 并将Log添加子系统, 检测开始关闭Log时, 使用UOLO3D_INFO等是否合法
        log_.reset(new Log(context));
    }

    void Engine::RunFrame() {
        UOLO3D_INFO("run frame...");
    }

    bool Engine::IsExiting() {
        return exiting_;
    }
}