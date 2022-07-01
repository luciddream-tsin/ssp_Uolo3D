//
// Created by Administrator on 2022/7/1.
//

#ifndef UOLO3D_DRAWABLE_H
#define UOLO3D_DRAWABLE_H

#include "Scene/Component.h"

namespace Uolo3D {

    class Drawable : public Component{
        UOLO3D_CLASS_INFO(Drawable, Component)
    public:
        Drawable() = delete;
        Drawable(Context *context);

    };
}


#endif //UOLO3D_DRAWABLE_H
