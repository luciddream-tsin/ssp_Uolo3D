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

        void AddEventReceiver(Object *receiver, size_t eventType);
        vector<Object*> &GetReceiversGroup(size_t eventType){
            return eventReceiversMap_[eventType];
        };
        void RegisterSubsystem(Object *object);




    private:
        std::unordered_map<size_t, vector<Object*>> eventReceiversMap_;

        std::unordered_map<size_t, shared_ptr<Object>> subsystem_;

    };
}


#endif //SSP_UOLO3D_CONTEXT_H
