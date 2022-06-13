//
// Created by Administrator on 2022/6/13.
//

#ifndef SSP_UOLO3D_ENGINE_H
#define SSP_UOLO3D_ENGINE_H

namespace Uolo3D {
    class Context;

    class Engine {

    public:
        Engine() = delete;

        Engine(Context *context);

        void Run();


    };
}


#endif //SSP_UOLO3D_ENGINE_H
