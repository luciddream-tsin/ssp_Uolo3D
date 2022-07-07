//
// Created by Administrator on 2022/7/7.
//

#ifndef UOLO3D_TECHNIQUE_H
#define UOLO3D_TECHNIQUE_H


#include "Resource/TmpResource.h"
namespace Uolo3D {

    class Technique : public TmpResource{
        UOLO3D_CLASS_INFO(Technique, TmpResource)
    public:
        Technique() = delete;
        Technique(Context *context);

    };
}


#endif //UOLO3D_TECHNIQUE_H
