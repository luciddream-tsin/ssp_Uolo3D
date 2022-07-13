//
// Created by Administrator on 2022/7/1.
//

#ifndef UOLO3D_CAMERA_H
#define UOLO3D_CAMERA_H

#include "Scene/Component.h"

namespace Uolo3D {

    class Camera : public Component{
        UOLO3D_CLASS_INFO(Camera, Component)
    public:
        Camera() = delete;
        Camera(Context *context);

    };
}

#endif //UOLO3D_CAMERA_H
