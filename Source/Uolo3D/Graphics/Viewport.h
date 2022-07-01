//
// Created by Administrator on 2022/7/1.
//

#ifndef UOLO3D_VIEWPORT_H
#define UOLO3D_VIEWPORT_H

#include "Core/Object.h"
#include "Scene/Scene.h"
#include "Graphics/Camera.h"

namespace Uolo3D {

    class Viewport : public Object{
        UOLO3D_CLASS_INFO(Viewport, Object)

    public:
        Viewport() = delete;
        Viewport(Context *context, std::shared_ptr<Scene> scene, Camera *camera);

    };
}


#endif //UOLO3D_VIEWPORT_H
