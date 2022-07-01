//
// Created by Administrator on 2022/7/1.
//

#ifndef UOLO3D_LIGHT_H
#define UOLO3D_LIGHT_H

#include "Graphics/Drawable.h"

namespace Uolo3D {

    class Light : public Drawable{
        UOLO3D_CLASS_INFO(Light, Drawable)
    public:
        Light() = delete;
        Light(Context *context);

    };

}

#endif //UOLO3D_LIGHT_H
