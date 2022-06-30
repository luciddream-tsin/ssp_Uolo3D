//
// Created by Administrator on 2022/6/15.
//

#include "Graphics.h"
#include "IO/Log.h"

namespace Uolo3D{

    GAPI Graphics::gapi_ = GAPI::GAPI_Aurora;
    Graphics::Graphics(Context *context, GAPI gapi) : Object(context) {
        UOLO3D_DEBUG("Graphics Constructor");
        Graphics::gapi_ = gapi;

#ifdef UOLO3D_GL
        if (gapi == GAPI_OpenGL)
            Constructor_GL();
#endif
    }

    bool Graphics::SetScreenMode(unordered_map<string, params_union> engineParameters) {

        unordered_map<string, params_union> screenParameters;
        screenParameters[EP_WINDOW_POSITION_X].int_ = engineParameters[EP_WINDOW_POSITION_X].int_;
        screenParameters[EP_WINDOW_POSITION_Y].int_ = engineParameters[EP_WINDOW_POSITION_Y].int_;
        screenParameters[EP_WINDOW_SIZE_W].int_ = engineParameters[EP_WINDOW_SIZE_W].int_;
        screenParameters[EP_WINDOW_SIZE_H].int_ = engineParameters[EP_WINDOW_SIZE_H].int_;
        screenParameters[EP_FULL_SCREEN].bool_ = engineParameters[EP_FULL_SCREEN].bool_;
        screenParameters[EP_OPENGL].bool_ = engineParameters[EP_OPENGL].bool_;
        return SetScreenMode_GL(screenParameters);

    }


    void Graphics::BeginFrame() {

    }

    void Graphics::EndFrame() {

        //tmp 临时的 SDL swap 测试 ------beg-------
        while (SDL_PollEvent(&event_)) {
            if (event_.type == SDL_QUIT) return;
        }
        SDL_GL_SwapWindow(window_);
        //tmp 临时的 SDL swap 测试 ------end-------

    }
}
