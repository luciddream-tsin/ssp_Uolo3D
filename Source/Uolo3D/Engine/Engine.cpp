//
// Created by Administrator on 2022/6/13.
//

#include "Engine.h"
#include "Core/Context.h"
#include "iostream"


namespace Uolo3D {
    Engine::Engine(Context *context) : exiting_(false){

    }

    void Engine::RunFrame() {
        std::cout << "run frame..." << std::endl;
    }

    bool Engine::IsExiting() {
        return exiting_;
    }
}