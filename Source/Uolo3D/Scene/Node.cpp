//
// Created by Administrator on 2022/7/1.
//

#include "Node.h"
#include "Scene.h"
#include "IO/Log.h"

namespace Uolo3D{

    Node::Node(Context *context, std::string name) : Object(context){
        components_.clear();
        children_.clear();
        name_ = name;
    }

    Node *Node::CreateChild(std::string name, unsigned int id) {
        assert(scene_);
        Node *newNode = new Node(context_, name);
        newNode->scene_ = scene_;

        //如果给定的id不是默认的0， 检查场景中是否有该id的节点， 如果有
        //重新生成一个没被使用的id， 否则直接设置给定的id

        if (!id || scene_->GetNode(id))
            id = scene_->GetFreeNodeID();
        newNode->SetID(id);
        AddChild(newNode);
        return newNode;
    }

    void Node::AddChild(Node *node) {
        assert(node);
        children_.emplace_back(node);
    }

    bool Node::SetID(unsigned int id) {
        if (GetNode(id)) {
            UOLO3D_ERROE("Set ID failed, the id already exist in scene.");
            return false;
        }else {
            this->id_ = id;
            return true;
        }
    }

    Node *Node::GetNode(unsigned int id) {
        for (int i = 0; i < children_.size(); ++i) {
            Node *child = children_[i].get();
            assert(child);
            if (child->id_ == id){
                return child;
            }
        }
        return nullptr;
    }

    unsigned int Node::GetFreeNodeID() {
        UOLO3D_LOG_("need generate new id.................");
        unsigned int maxID = -UINT32_MAX;
        for (int i = 0; i < children_.size(); ++i) {
            Node *child = children_[i].get();
            assert(child);
            if (child->id_ > maxID) maxID = child->id_;
        }
        return ++maxID;
    }


    void Node::AddComponent(Component *component) {

    }
}
