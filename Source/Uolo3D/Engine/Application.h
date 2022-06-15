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
        //FIXME: 继承结构的中间类没有实现UOLO3D_CLASS_INFO宏, 但报错.
    public:
        Application(Context *context);
        virtual void Setup() {};
        virtual void Start() {};
        virtual void Run();
        virtual void Exit() {};

    protected:
        std::shared_ptr<Engine> engine_;
        std::unordered_map<string, ep_type> engineParameters_;
    };
}


#endif //SSP_UOLO3D_APPLICATION_H
