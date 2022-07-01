//
// Created by Administrator on 2022/6/28.
//

#ifndef UOLO3D_SCENE_H
#define UOLO3D_SCENE_H

#include "Node.h"

namespace Uolo3D {
    class Scene : public Node{
        UOLO3D_CLASS_INFO(Scene, Node)
    public:
        Scene() = delete;
        Scene(Context *context);

    };
}


#endif //UOLO3D_SCENE_H
