//
// Created by Administrator on 2022/6/13.
//

#ifndef SSP_UOLO3D_OBJECT_H
#define SSP_UOLO3D_OBJECT_H

namespace Uolo3D {
    class Context;
    class Object {
    public:
        Object(Context *context);


    protected:
        Context *context_;

    };
}


#endif //SSP_UOLO3D_OBJECT_H
