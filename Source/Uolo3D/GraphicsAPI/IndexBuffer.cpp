//
// Created by Administrator on 2022/7/13.
//

#include "IndexBuffer.h"
namespace Uolo3D{

    IndexBuffer::IndexBuffer(Context *context) : Object(context){
        buffer_.reset(nullptr);
    }

    void IndexBuffer::ResetBuffer(unsigned char *buffer) {
        buffer_.reset(buffer);
    }

}
