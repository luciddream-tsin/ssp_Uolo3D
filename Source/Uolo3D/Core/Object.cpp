//
// Created by Administrator on 2022/6/13.
//

#include "Object.h"
#include "Context.h"
#include <functional>

namespace Uolo3D{

    //-----------------------------------------------ClassInfo
    ClassInfo::ClassInfo(const string name, const ClassInfo *baseClassInfo) {
        typeName_ = name;
        typeHash_ = hash<string>()(name);
        baseClassInfo_ = baseClassInfo;
    }


    bool ClassInfo::IsClassOf(size_t typeHash) const {

        auto current = this;
        while (current){
            if (current->GetType() == typeHash_){
                return true;
            }
            current = current->baseClassInfo_;
        }
        return false;
    }

    //-----------------------------------------------Object
    Object::Object(Context *context):context_(context) {

    }

    //TODO: 释放一个对象的时候自动移除它所注册的事件
    Object::~Object() {

    }

    void Object::SubscribeToEvent(size_t eventType, EventHandler *eventHandler) {

        if (!eventHandler) return;
        //处理器也拥有事件类型, 供事件发生时从eventHandlers_这个vector中拿出处理器, 判断它是否该响应
        //again, vector 不具有map那样的天然分类特性.
        eventHandler->SetEventType(eventType);
        eventHandlers_.emplace_front(eventHandler);

        //注册到Context
        context_->AddEventReceiver(this, eventType);

    }

    void Object::OnEvent(size_t eventType) {

        for(auto handler : eventHandlers_){

            if (handler->IsType(eventType)){
                handler->Exec();
            }

        }

    }

    void Object::SendEvent(size_t eventType) {
        auto &receiversGroup = context_->GetReceiversGroup(eventType);

        for(auto obj:receiversGroup){
            obj->OnEvent(eventType);
        }

    }

    //-----------------------------------------------EventHandler

    EventHandler::EventHandler(std::function<void(size_t)> handlerFunc) {
        handler_ = handlerFunc;
    }





}