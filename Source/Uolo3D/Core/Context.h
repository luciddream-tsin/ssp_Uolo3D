//
// Created by Administrator on 2022/6/13.
//

#ifndef SSP_UOLO3D_CONTEXT_H
#define SSP_UOLO3D_CONTEXT_H

#include "Object.h"
#include <vector>
#include "unordered_map"

namespace Uolo3D {


    class Context{
    public:
        Context();

        //---------------event related code---------------------
        void AddEventReceiver(Object *receiver, size_t eventType);
        vector<Object*> &GetReceiversGroup(size_t eventType){
            return eventReceiversMap_[eventType];
        };



        //---------------get/set subsystem----------------------
        Object *RegisterSubsystem(Object *object);
        template<typename T>
        T* GetSubsystem(){
            return (T*)(subsystem_[T::GetTypeStatic()]).get();
        };

        //---------------sdl related code-----------------------
        bool RequireSDL(unsigned int sdlFlags);




    private:
        std::unordered_map<size_t, vector<Object*>> eventReceiversMap_;

        std::unordered_map<size_t, shared_ptr<Object>> subsystem_;

    };
}


#endif //SSP_UOLO3D_CONTEXT_H
