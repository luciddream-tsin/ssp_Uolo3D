//
// Created by Administrator on 2022/6/16.
//

#include "Core/Object.h"

namespace Uolo3D {
    class GraphicsImpl_GL : public Object {
        UOLO3D_CLASS_INFO(GraphicsImpl_GL, Object)
    public:
        GraphicsImpl_GL() = delete;
        GraphicsImpl_GL(Context *context): Object(context){

        }

    };
}