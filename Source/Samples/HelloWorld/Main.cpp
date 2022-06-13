//
// Created by Administrator on 2022/6/13.
//

#include "Engine/Engine.h"
#include "Core/Context.h"
#include "memory"

using namespace Uolo3D;

int main(){
    std::shared_ptr<Context> context {new Context()};
    Engine engine{context.get()};
    engine.Run();
}