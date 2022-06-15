//
// Created by Administrator on 2022/6/13.
//

#include "Context.h"

namespace Uolo3D{
    Context::Context() {

    }

    void Context::AddEventReceiver(Object *receiver, size_t eventType) {
        //TODO: 一个对象对同一个事件注册多次应给出提示或直接禁止
        auto &receiversGroup = eventReceiversMap_[eventType];
        receiversGroup.push_back(receiver);
    }

    void Context::RegisterSubsystem(Object *object) {
        if (!object) return;
        subsystem_[object->GetType()].reset(object);
    }


}