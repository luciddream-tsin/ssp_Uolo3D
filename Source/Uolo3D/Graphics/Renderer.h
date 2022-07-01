//
// Created by Administrator on 2022/6/15.
//

#ifndef UOLO3D_RENDERER_H
#define UOLO3D_RENDERER_H

#include "Core/Object.h"
#include "vector"

namespace Uolo3D{
    class Viewport;
    class Renderer : public Object{
    UOLO3D_CLASS_INFO(Renderer(), Object)

    public:
        Renderer(Context *context);

        void Update();

        void SetViewport(int index, Viewport *viewport);

    private:

        std::vector<std::shared_ptr<Viewport>> viewports_;
    };
}

#endif //UOLO3D_RENDERER_H
