//
// Created by Administrator on 2022/7/1.
//

#ifndef UOLO3D_STATICMODEL_H
#define UOLO3D_STATICMODEL_H


#include "Drawable.h"
namespace Uolo3D {
    class StaticModel : public Drawable{
        UOLO3D_CLASS_INFO(StaticModel, Drawable)
    public:
        StaticModel() = delete;
        StaticModel(Context *context);

    };
}


#endif //UOLO3D_STATICMODEL_H
