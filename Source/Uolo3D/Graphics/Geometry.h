//
// Created by Administrator on 2022/7/7.
//

#ifndef UOLO3D_GEOMETRY_H
#define UOLO3D_GEOMETRY_H

#include "Core/Object.h"
namespace Uolo3D {
    class StaticModel;

    class Geometry : public Object {
    UOLO3D_CLASS_INFO(Geometry, Object)

    friend StaticModel;
    public:
        Geometry() = delete;

        Geometry(Context *context);

    private:
        float distanceLOD_ = 0.0;
        uint32_t primitiveType_ = 0;
        uint32_t vbRef_ = 0;
        uint32_t ibRef_ = 0;
        uint32_t indexStart_ = 0;
        uint32_t indexCount_ = 0;

    };
}


#endif //UOLO3D_GEOMETRY_H
