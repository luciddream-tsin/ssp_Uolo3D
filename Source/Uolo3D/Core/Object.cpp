//
// Created by Administrator on 2022/6/13.
//

#include "Object.h"

namespace Uolo3D{
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

    Object::Object(Context *context):context_(context) {

    }
}