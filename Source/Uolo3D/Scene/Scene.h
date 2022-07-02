//
// Created by Administrator on 2022/6/28.
//

#ifndef UOLO3D_SCENE_H
#define UOLO3D_SCENE_H

#include "Node.h"
#include "IO/Log.h"

namespace Uolo3D {
    class Scene : public Node{
        UOLO3D_CLASS_INFO(Scene, Node)
    public:
        Scene() = delete;
        Scene(Context *context, std::string name);

        void TestFun(){
            UOLO3D_LOG_("fun tsest");
        };

    };
}


#endif //UOLO3D_SCENE_H
