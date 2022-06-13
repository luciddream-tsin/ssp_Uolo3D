//
// Created by Administrator on 2022/6/13.
//

#ifndef SSP_UOLO3D_APPLICATION_H
#define SSP_UOLO3D_APPLICATION_H


#include "Core/Object.h"

namespace Uolo3D {

    class Application : public Object{
    public:
        Application(Context *context);
        virtual void Setup() = 0;
        virtual void Start() = 0;
        virtual void Run() = 0;
        virtual void Stop() = 0;
        virtual void Exit() = 0;
    };
}


#endif //SSP_UOLO3D_APPLICATION_H
