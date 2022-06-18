//
// Created by Administrator on 2022/6/13.
//

#ifndef SSP_UOLO3D_ENGINE_H
#define SSP_UOLO3D_ENGINE_H
#include "Core/Object.h"
#include "unordered_map"
#include "EngineDefs.h"


namespace Uolo3D {
    class Context;
    class Log;

    class Engine : public Object{
        UOLO3D_CLASS_INFO(Engine, Object)

    public:
        Engine() = delete;
        Engine(Context *context);

        bool Initialize(unordered_map<string, params_union> engineParameters);

        void RunFrame();
        bool IsExiting();
    private:
        void Update();
        void Render();
        void FrameLimit();

    private:
        bool exiting_;

    };
}


#endif //SSP_UOLO3D_ENGINE_H
