//
// Created by Administrator on 2022/6/13.
//

#include "Application.h"

namespace Uolo3D{
    Application::Application(Context *context): Object(context), engineParameters_() {
        engine_.reset(new Engine(context));

    }

    void Application::Run() {

        Setup();
        engine_->Initialize(engineParameters_);
        Start();

        while (!engine_->IsExiting())
            engine_->RunFrame();

        Exit();
    }


}
