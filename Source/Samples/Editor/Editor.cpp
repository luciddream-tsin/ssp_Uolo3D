//
// Created by Administrator on 2022/6/13.
//


#include "Editor.h"
#include "IO/Log.h"
#include "Engine/EngineDefs.h"
#include "iostream"
#include "Graphics/StaticModel.h"
#include "Graphics/Light.h"
#include "Graphics/Camera.h"
#include "Graphics/Viewport.h"
#include "Graphics/Renderer.h"
#include "Core/Context.h"


Editor::Editor(Context *context): Application(context){

}

void Editor::Setup() {
    UOLO3D_LOG_("Hello World Setup Called.");

    engineParameters_[EP_OPENGL].bool_ = true;
    engineParameters_[EP_FULL_SCREEN].bool_ = false;
    engineParameters_[EP_LOG_LEVEL].int_ = LOG_DEBUG;
    engineParameters_[EP_WINDOW_POSITION_X].int_ = 500;
    engineParameters_[EP_WINDOW_POSITION_Y].int_ = 200;
    engineParameters_[EP_WINDOW_SIZE_W].int_ = 800;
    engineParameters_[EP_WINDOW_SIZE_H].int_ = 620;

}

void Editor::Start() {
    UOLO3D_LOG_("Hello World Start Called.");

    // create a scene
    scene_.reset(new Scene(context_, "EditorScene"));

    //-------------NULL pointer but not exit----------------beg--
    // 回忆深度探索C++对象模型, 多用assert, 该宏只在debug模式下生效.
    // c++ 底层将函数编译成面相过程的语言, 调用成员函数默认传入第一个参数 this
    //------------------------------------------------------end--

    //--------------light----------------------------------------
    Node *lightNode = scene_->CreateChild("LightNode");
    assert(lightNode);
    lightNode->CreateComponent<Light>();

    //--------------static model----------------------------------
    Node *cubeNode = scene_->CreateChild("CubeNode");
    assert(cubeNode);
    StaticModel *cubeModel = cubeNode->CreateComponent<StaticModel>();
    cubeModel->LoadModelResource("../Content/CoreData/Models/Box.mdl");
    cubeModel->LoadMaterialResource("../Content/CoreData/Materials/Stone.xml");

    //--------------camera----------------------------------------
    Node *cameraNode = scene_->CreateChild("cameraNode");
    assert(cameraNode);
    Camera *camera = cameraNode->CreateComponent<Camera>();

    //--------------viewport---------------------------------------
    std::shared_ptr<Viewport> viewport(new Viewport(context_, scene_, cameraNode->GetComponent<Camera>()));
    context_->GetSubsystem<Renderer>()->SetViewport(0, viewport.get());

}



void Editor::Exit() {
    UOLO3D_INFO("Hello World Exit Called.");
}
