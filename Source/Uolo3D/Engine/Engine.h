//
// Created by Administrator on 2022/6/13.
//

#ifndef SSP_UOLO3D_ENGINE_H
#define SSP_UOLO3D_ENGINE_H
#include "Core/Object.h"

namespace Uolo3D {
    class Context;
    class Log;

    class Engine : public Object{
        UOLO3D_CLASS_INFO(Engine, Object)

    public:
        Engine() = delete;

        Engine(Context *context);

        void RunFrame();
        bool IsExiting();

    private:
        bool exiting_;
        std::shared_ptr<Log> log_;// tmp for test

    };
}


#endif //SSP_UOLO3D_ENGINE_H
