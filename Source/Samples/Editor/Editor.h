//
// Created by Administrator on 2022/6/13.
//

#ifndef SSP_UOLO3D_HELLOWORLD_H
#define SSP_UOLO3D_HELLOWORLD_H

#include "Engine/Application.h"
#include "Scene/Scene.h"

using namespace Uolo3D;
class Editor : public Application{
    UOLO3D_CLASS_INFO(Editor, Application)

public:
    Editor(Context *context);

    void Setup() override;
    void Start() override;

    void Exit() override;


private:
    std::shared_ptr<Scene> scene_;


};


#endif //SSP_UOLO3D_HELLOWORLD_H
