//
// Created by Administrator on 2022/6/13.
//

#ifndef SSP_UOLO3D_HELLOWORLD_H
#define SSP_UOLO3D_HELLOWORLD_H

#include "Engine/Application.h"
using namespace Uolo3D;
class HelloWorld :public Application{
    UOLO3D_CLASS_INFO(HelloWorld, Application)

public:
    HelloWorld(Context *context);

    void Setup() override;
    void Start() override;

    void Stop() override;
    void Exit() override;


};


#endif //SSP_UOLO3D_HELLOWORLD_H
