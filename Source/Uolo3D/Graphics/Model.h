//
// Created by Administrator on 2022/7/7.
//

#ifndef UOLO3D_MODEL_H
#define UOLO3D_MODEL_H

#include "Resource/TmpResource.h"

namespace Uolo3D {

    class Model : public TmpResource{
        UOLO3D_CLASS_INFO(Model, TmpResource)
    public:
        Model() = delete;
        Model(Context *context);

    };
}


#endif //UOLO3D_MODEL_H
