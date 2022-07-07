//
// Created by Administrator on 2022/7/7.
//

#ifndef UOLO3D_TEXTURE_H
#define UOLO3D_TEXTURE_H

#include "Resource/TmpResource.h"

namespace Uolo3D {

    class Texture : public TmpResource{
        UOLO3D_CLASS_INFO(Texture, TmpResource)
    public:
        Texture() = delete;
        Texture(Context *context);

    };
}


#endif //UOLO3D_TEXTURE_H
