//
// Created by Administrator on 2022/6/13.
//

#include "Core/Context.h"
#include "memory"
#include "HelloWorld.h"

using namespace Uolo3D;

int main(){
    std::shared_ptr<Context> context {new Context()};
    HelloWorld helloWorld{context.get()};
    helloWorld.Run();
}