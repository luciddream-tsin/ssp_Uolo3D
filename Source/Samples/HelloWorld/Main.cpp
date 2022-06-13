//
// Created by Administrator on 2022/6/13.
//

#include "Core/Context.h"
#include "memory"
#include "HelloWorld.h"
#include "IO/Log.h"

using namespace Uolo3D;

int main(){
    std::shared_ptr<Context> context {new Context()};
    std::shared_ptr<HelloWorld> helloWorld{new HelloWorld(context.get())};
    //helloWorld->Run();
    //test log:
    Log log(context.get());
    log.Write(LOG_WARNING, "this is a warning!");


}