//
// Created by Administrator on 2022/6/13.
//

#include "Context.h"
#include "IO/Log.h"
#include "SDL.h"

namespace Uolo3D{
    Context::Context() {

    }

    void Context::AddEventReceiver(Object *receiver, size_t eventType) {
        //TODO: 一个对象对同一个事件注册多次应给出提示或直接禁止
        auto &receiversGroup = eventReceiversMap_[eventType];
        receiversGroup.push_back(receiver);
    }

    Object* Context::RegisterSubsystem(Object *object) {
        if (!object) return nullptr;
        subsystem_[object->GetType()].reset(object);
        return object;
    }

    bool Context::RequireSDL(unsigned int sdlFlags) {

        UOLO3D_DEBUG("Initialing SDL");
        auto r = SDL_Init(0);
        if (r != 0 ){
            //UOLO3D_ERROE("Failed to initialized SDL: " + string(SDL_GetError()));
        }

        SDL_InitSubSystem(sdlFlags);
        return false;

    }


}