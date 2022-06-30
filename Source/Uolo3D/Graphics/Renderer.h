//
// Created by Administrator on 2022/6/15.
//

#ifndef UOLO3D_RENDERER_H
#define UOLO3D_RENDERER_H

#include "Core/Object.h"

namespace Uolo3D{
    class Renderer : public Object{
    UOLO3D_CLASS_INFO(Renderer(), Object)

    public:
        Renderer(Context *context);

        void Update();


    };
}

#endif //UOLO3D_RENDERER_H
