//
// Created by Administrator on 2022/7/1.
//

#ifndef UOLO3D_NODE_H
#define UOLO3D_NODE_H

#include "Core/Object.h"
#include "Scene/Component.h"
#include "vector"
#include "mathfu/vector.h"
#include "mathfu/quaternion.h"

namespace Uolo3D {
    class Scene;
    class Node : public Object{
        UOLO3D_CLASS_INFO(Node, Object)
    public:
        Node() = delete;
        Node(Context *context);

        Node *CreateChild(std::string name, unsigned id = 0);
        void AddChild(Node *node);
        void SetID(unsigned id);

        template<class T> T* CreateComponent(unsigned id = 0){

        };
        void AddComponent(Component *component);

    private:
        Node *parent_;
        Scene *scene_;
        unsigned id_;

        std::vector<std::shared_ptr<Node>> children_;
        std::vector<std::shared_ptr<Component>> components_;

        mathfu::Vector<float, 3> position_;
        mathfu::Quaternion<float> rotation_;
        mathfu::Vector<float, 3> scale_;

    };
}


#endif //UOLO3D_NODE_H
