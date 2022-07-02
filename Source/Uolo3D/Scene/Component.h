//
// Created by Administrator on 2022/7/1.
//

#ifndef UOLO3D_COMPONENT_H
#define UOLO3D_COMPONENT_H
#include "Core/Object.h"

namespace Uolo3D {

    //组件分为可绘制和不可绘制, 例如继承模型
    //Component <- Drawable <- StaticModel
    //Component <- Drawable <- Light
    //Component <- Camera

    class Component : public Object{
        UOLO3D_CLASS_INFO(Component, Object)
    public:
        Component() = delete;
        Component(Context *context);

    };
}


#endif //UOLO3D_COMPONENT_H
