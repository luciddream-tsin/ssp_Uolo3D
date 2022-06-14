//
// Created by Administrator on 2022/6/13.
//

#include "HelloWorld.h"
#include "IO/Log.h"

HelloWorld::HelloWorld(Context *context): Application(context){

}

void HelloWorld::Setup() {
    UOLO3D_INFO("Hello World Setup Called.");
}

void HelloWorld::Start() {
    UOLO3D_INFO("Hello World Start Called.");
}



void HelloWorld::Exit() {
    UOLO3D_INFO("Hello World Exit Called.");
}
