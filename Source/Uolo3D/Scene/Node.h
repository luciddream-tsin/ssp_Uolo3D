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
    class Camera;
    class Node : public Object{
        UOLO3D_CLASS_INFO(Node, Object)
    public:
        Node() = delete;
        Node(Context *context, std::string name);

        Node *CreateChild(std::string name, unsigned id = 0);
        void AddChild(Node *node);
        bool SetID(unsigned id);
        Node *GetNode(unsigned id);
        unsigned GetFreeNodeID();


        // NOTE: 模板函数的声明定义不能分离
        template<class T> T* CreateComponent(unsigned id = 0){
            components_.emplace_back(new T(context_));
            return (T*)components_.back().get();
        };

        template<class T> T* GetComponent(){
            int size = components_.size();
            for (int i = 0; i < components_.size(); ++i) {
                Component *component = components_[i].get();
                if (component->GetType() == T::GetTypeStatic()){
                    return static_cast<T*>(component);
                }
            }
            return (T*)nullptr;
        };
        void AddComponent(Component *component);

    protected:
        Scene *scene_;

    private:
        std::string name_;
        Node *parent_;
        unsigned id_;

        std::vector<std::shared_ptr<Node>> children_;
        std::vector<std::shared_ptr<Component>> components_;

        mathfu::Vector<float, 3> position_;
        mathfu::Quaternion<float> rotation_;
        mathfu::Vector<float, 3> scale_;

    };
}


#endif //UOLO3D_NODE_H
