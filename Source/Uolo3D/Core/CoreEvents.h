//
// Created by Administrator on 2022/6/14.
//

#ifndef UOLO3D_COREEVENTS_H
#define UOLO3D_COREEVENTS_H
//一个简单的事件系统设计实现:
//Object类提供订阅事件和发送事件功能, 不同的Object通过向Context注册订阅和发送"事件类型和相关的数据"完成事件交互
//具体过程:
//1.Object类提供订阅事件函数, 传入事件类型eventType, 和 evenHandler(处理该事件的句柄类)

//2.Object类内部维护一个eventHandlers_链表,来保存该类监听的所有事件的处理器, 调用订阅事件函数的时候,
//let the eventHandler insert in the front of the linklist.
//这只是个链表, 没有处理器和事件类型的对应关系, 因此在处理器中也要保存一份对应的eventType

//3.向Context注册 本对象要监听该事件, 即当该事件发生时我要参与处理,
// context_->AddEventReceiver(this, eventType); context维护一个hashmap保存不同事件注册的接收者

//4.Object类提发送事件函数, 当发送事件时, 通过eventType和保存的hashmap找到所有该事件的监听者,遍历调用他们的OnEvent

//5.Object类提供OnEvent函数, 寻找eventHandlers_中对应该事件的处理器,并调用.

//note: 我们没有增加对特定发送者的事件过滤, 详情看Urho3D源码, 其他功能后期添加.

namespace Uolo3D {
    //每一个事件的ID是通过string name生成的, 同时伴随一个string name 的子命名空间, 定义一些该事件的专用数据
    #define UOLO3D_EVENT(eventID, eventName) static const size_t eventID = std::hash<std::string>()(#eventName); namespace eventName

    UOLO3D_EVENT(E_ENDFRAME, EndFrame){

    }


}



#endif //UOLO3D_COREEVENTS_H
