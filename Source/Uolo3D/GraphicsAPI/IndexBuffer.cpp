//
// Created by Administrator on 2022/7/13.
//

#include <cassert>
#include "IndexBuffer.h"
namespace Uolo3D{

    IndexBuffer::IndexBuffer(Context *context) : Object(context),
    indexCount_(0), indexSize_(0){

        buffer_.reset(nullptr);
    }

    void IndexBuffer::ResetBuffer(unsigned char *buffer) {
        assert(buffer);
        buffer_.reset(buffer);
    }

    void IndexBuffer::SetSize(uint32_t indexCount, uint32_t indexSize) {
        indexCount_ = indexCount;
        indexSize_ = indexSize;
    }

}
