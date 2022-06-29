//
// Created by Administrator on 2022/6/13.
//

#include "Editor.h"
#include "IO/Log.h"
#include "Engine/EngineDefs.h"
#include "iostream"

Editor::Editor(Context *context): Application(context){

}

void Editor::Setup() {
    UOLO3D_LOG_("Hello World Setup Called.");

    engineParameters_[EP_OPENGL].bool_ = true;
    engineParameters_[EP_FULL_SCREEN].bool_ = false;
    engineParameters_[EP_LOG_LEVEL].int_ = LOG_DEBUG;
    engineParameters_[EP_WINDOW_POSITION_X].int_ = 500;
    engineParameters_[EP_WINDOW_POSITION_Y].int_ = 200;
    engineParameters_[EP_WINDOW_SIZE_W].int_ = 1200;
    engineParameters_[EP_WINDOW_SIZE_H].int_ = 820;

}

void Editor::Start() {
    UOLO3D_LOG_("Hello World Start Called.");

    // create a scene

    // create a child node of scene
    // add a light component

    // create a child node of scene
    // add a static model component

    // create a child node of scene
    // add a camera component

    // create a viewport (context, scene, camera)
    // get renderer and set a viewport of it.


}



void Editor::Exit() {
    UOLO3D_INFO("Hello World Exit Called.");
}
