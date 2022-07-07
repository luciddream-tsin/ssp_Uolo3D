//
// Created by Administrator on 2022/7/7.
//

#ifndef UOLO3D_TMPRESOURCE_H
#define UOLO3D_TMPRESOURCE_H

#include "Core/Object.h"

namespace Uolo3D {

    class TmpResource : public Object{
        UOLO3D_CLASS_INFO(TmpResource, Object)
    public:
        TmpResource() = delete;
        TmpResource(Context *context);

    };
}


#endif //UOLO3D_TMPRESOURCE_H
