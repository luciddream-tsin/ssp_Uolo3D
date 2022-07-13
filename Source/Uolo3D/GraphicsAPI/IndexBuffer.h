//
// Created by Administrator on 2022/7/13.
//

#ifndef UOLO3D_INDEXBUFFER_H
#define UOLO3D_INDEXBUFFER_H
#include "Core/Object.h"


namespace Uolo3D {

    class IndexBuffer : public Object{
        UOLO3D_CLASS_INFO(IndexBuffer, Object)
    public:
        IndexBuffer() = delete;
        IndexBuffer(Context *context);

        void SetSize(uint32_t indexCount, uint32_t indexSize);
        void ResetBuffer(unsigned char *buffer);


    private:
        uint32_t indexCount_;
        uint32_t indexSize_;
        unique_ptr<unsigned char []> buffer_;
    };
}


#endif //UOLO3D_INDEXBUFFER_H
