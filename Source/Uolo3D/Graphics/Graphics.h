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
#include "GraphicsAPI/OpenGL/GLGraphicsImpl.h"

namespace Uolo3D {

    struct ScreenModeParams{

    };


    class Graphics : public Object {
        UOLO3D_CLASS_INFO(Graphics, Object)
    public:
        friend class Renderer;

        Graphics() = delete;
        Graphics(Context *context, GAPI gapi);

        bool SetScreenMode(unordered_map<string, params_union> engineParameters);

        void Maximize();

        void BeginFrame();
        void EndFrame();



    private:
#ifdef UOLO3D_GL
        void Constructor_GL();
        void Destructor_GL();
        bool SetScreenMode_GL(unordered_map<string, params_union> screenParameters);

        void Restore_GL();
        void ResetRenderTarget_GL();
        void SetViewport_GL();

        void Draw_GL();

        GraphicsImpl_GL* GetImpl_OGL() const
        {
            // assert(Graphics::Get == GAPI_OPENGL);
            return static_cast<GraphicsImpl_GL*>(impl_);
        }
#endif


    private:

        static GAPI gapi_;
        string apiName_="";

        void * impl_{nullptr};

        SDL_Window *window_{nullptr};


        //tmp
        SDL_Event event_;

    };
}


#endif //UOLO3D_GRAPHICS_H
