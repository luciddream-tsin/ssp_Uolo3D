//
// Created by Administrator on 2022/6/13.
//

#ifndef SSP_UOLO3D_APPLICATION_H
#define SSP_UOLO3D_APPLICATION_H


#include "Core/Object.h"
#include "Engine.h"
#include "memory"

namespace Uolo3D {
    class Application : public Object{
    public:
        Application(Context *context);
        virtual void Setup() {};
        virtual void Start() {};
        virtual void Run();
        virtual void Stop() {};
        virtual void Exit() {};

    protected:
        std::shared_ptr<Engine> engine_;
    };
}


#endif //SSP_UOLO3D_APPLICATION_H