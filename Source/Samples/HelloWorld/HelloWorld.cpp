//
// Created by Administrator on 2022/6/13.
//

#include "HelloWorld.h"
#include "IO/Log.h"
#include "Engine/EngineDefs.h"
#include "iostream"

HelloWorld::HelloWorld(Context *context): Application(context){

}

void HelloWorld::Setup() {
    UOLO3D_LOG_("Hello World Setup Called.");

    engineParameters_[EP_OPENGL].bool_ = true;
    engineParameters_[EP_FULL_SCREEN].bool_ = false;
    engineParameters_[EP_LOG_LEVEL].int_ = LOG_DEBUG;
    engineParameters_[EP_WINDOW_POSITION_X].int_ = 800;
    engineParameters_[EP_WINDOW_POSITION_Y].int_ = 300;
    engineParameters_[EP_WINDOW_SIZE_W].int_ = 600;
    engineParameters_[EP_WINDOW_SIZE_H].int_ = 320;

}

void HelloWorld::Start() {
    UOLO3D_LOG_("Hello World Start Called.");
}



void HelloWorld::Exit() {
    UOLO3D_INFO("Hello World Exit Called.");
}
