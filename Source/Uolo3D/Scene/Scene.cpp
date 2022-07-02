//
// Created by Administrator on 2022/6/28.
//

#include "Scene.h"
namespace Uolo3D{
    Scene::Scene(Context *context, std::string name) : Node(context, name) {
        scene_ = this;
    }


}
