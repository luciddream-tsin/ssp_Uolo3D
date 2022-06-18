//
// Created by Administrator on 2022/6/16.
//

#include "Graphics/Graphics.h"
#include "Core/Context.h"
#include "SDL.h"
namespace Uolo3D{
    void Graphics::Constructor_GL() {
        apiName_ = "OpenGL";
        //一些GL相关引擎设置, 如shader路径/结尾拓展, GL图形朝向, 阴影格式等
        //...

        //目前我们只在这里初次初始化SDL, 因为你要显示东西, 使用图形API的时候,
        //最先打开一个窗口是必须的, 当然如果你想看见它的话
        context_->RequireSDL(SDL_INIT_VIDEO);

    }

    bool Graphics::SetScreenMode_GL(unordered_map<string, params_union> screenParameters) {
        //TODO: release OpenGL

        unsigned int flags = 0;

        //TODO: Comment fellow SDL_GL_* program.

        int x = screenParameters[EP_WINDOW_POSITION_X].int_;
        int y = screenParameters[EP_WINDOW_POSITION_Y].int_;
        int w = screenParameters[EP_WINDOW_SIZE_W].int_;
        int h = screenParameters[EP_WINDOW_SIZE_H].int_;

        window_ = SDL_CreateWindow("", x, y, w, h, flags);

        return true;
    }
}