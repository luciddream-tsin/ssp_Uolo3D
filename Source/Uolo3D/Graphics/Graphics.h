//
// Created by Administrator on 2022/6/15.
//

#ifndef UOLO3D_GRAPHICS_H
#define UOLO3D_GRAPHICS_H

#include "Core/Object.h"
#include "GraphicsAPI/GraphicsDef.h"
#include "Engine/EngineDefs.h"
#include "unordered_map"
#include "SDL.h"

namespace Uolo3D {

    struct ScreenModeParams{

    };


    class Graphics : public Object {
        UOLO3D_CLASS_INFO(Graphics, Object)
    public:
        Graphics() = delete;
        Graphics(Context *context, GAPI gapi);

        bool SetScreenMode(unordered_map<string, params_union> engineParameters);



    private:
#ifdef UOLO3D_GL
        void Constructor_GL();
        void Destructor_GL();

        bool SetScreenMode_GL(unordered_map<string, params_union> screenParameters);
#endif


    private:

        static GAPI gapi_;
        string apiName_;

        void * impl_;

        SDL_Window *window_;

    };
}


#endif //UOLO3D_GRAPHICS_H
