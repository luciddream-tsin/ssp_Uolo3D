//
// Created by Administrator on 2022/6/16.
//

#include "Core/Object.h"
#include "GL/glew.h"

using SDL_GLContext = void *;
namespace Uolo3D {
    class GraphicsImpl_GL{

        friend class Graphics;
    public:
        GraphicsImpl_GL(){

        }

    private:
        SDL_GLContext context_{};
    };
}