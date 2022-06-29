//
// Created by Administrator on 2022/6/16.
//

#include <cassert>
#include "Graphics/Graphics.h"
#include "Core/Context.h"
#include "SDL.h"
#include "IO/Log.h"
#include "GL/glew.h"

namespace Uolo3D{
    void Graphics::Constructor_GL() {
        apiName_ = "OpenGL";
        impl_ = new GraphicsImpl_GL();
        //一些GL相关引擎设置, 如shader路径/结尾拓展, GL图形朝向, 阴影格式等
        //...

        //目前我们只在这里初次初始化SDL, 因为你要显示东西, 使用图形API的时候,
        //最先打开一个窗口是必须的, 当然如果你想看见它的话
        context_->RequireSDL(SDL_INIT_VIDEO);

    }

    void Graphics::Destructor_GL() {
        if (impl_) delete impl_;

    }

    bool Graphics::SetScreenMode_GL(unordered_map<string, params_union> screenParameters) {
        //TODO: release OpenGL

        unsigned flags = SDL_WINDOW_SHOWN;


        //TODO: Comment fellow SDL_GL_* program.

        int x = screenParameters[EP_WINDOW_POSITION_X].int_;
        int y = screenParameters[EP_WINDOW_POSITION_Y].int_;
        int w = screenParameters[EP_WINDOW_SIZE_W].int_;
        int h = screenParameters[EP_WINDOW_SIZE_H].int_;

        bool isFullScreen = screenParameters[EP_FULL_SCREEN].bool_;
        if (isFullScreen)
            flags |=  SDL_WINDOW_FULLSCREEN;

        bool isOpenGL = screenParameters[EP_OPENGL].bool_;
        if (isOpenGL)
            flags |= SDL_WINDOW_OPENGL;

        window_ = SDL_CreateWindow("", x, y, w, h, flags);

        Restore_GL();
        return true;
    }

    void Graphics::Restore_GL() {
        if (!window_){ return;}

        GraphicsImpl_GL *impl = GetImpl_OGL();
        if (!impl->context_){

            // create sdl context
            impl->context_ = SDL_GL_CreateContext(window_);
            if (!impl->context_){
                UOLO3D_LOG_("Could not create OpenGL context");//SDL_GetError()
                return;
            }
            // init glew
            GLenum err = glewInit();
            if (err != GLEW_OK){
                UOLO3D_LOG_("Could not initialize OpenGL extensions");
                return;
            }

            // Create and bind a vertex array object that will stay in use throughout
            // unsigned vertexArrayObject;
            // glGenVertexArrays(1, &vertexArrayObject);
            // glBindVertexArray(vertexArrayObject);
        }

    }

    void Graphics::Maximize() {
        if (!window_) return;
        SDL_MaximizeWindow(window_);
    }


    void Graphics::Update_GL() {

        //tmp 临时的 SDL swap 测试 ------beg-------
        while (SDL_PollEvent(&event_)) {
            if (event_.type == SDL_QUIT) return;
        }
        SDL_GL_SwapWindow(window_);
        //tmp 临时的 SDL swap 测试 ------end-------



    }
}