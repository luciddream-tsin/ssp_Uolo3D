//
// Created by Administrator on 2022/7/1.
//

#ifndef UOLO3D_COMPONENT_H
#define UOLO3D_COMPONENT_H
#include "Core/Object.h"

namespace Uolo3D {


    class Component : public Object{
        UOLO3D_CLASS_INFO(Component, Object)
    public:
        Component() = delete;
        Component(Context *context);

    };
}


#endif //UOLO3D_COMPONENT_H
