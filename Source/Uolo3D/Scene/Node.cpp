//
// Created by Administrator on 2022/7/1.
//

#include "Node.h"

namespace Uolo3D{

    Node::Node(Context *context) : Object(context){
        components_.clear();
        children_.clear();

    }

    Node *Node::CreateChild(std::string name, unsigned int id) {

        return nullptr;
    }

    void Node::AddChild(Node *node) {

    }

    void Node::SetID(unsigned int id) {

    }


    void Node::AddComponent(Component *component) {

    }
}
