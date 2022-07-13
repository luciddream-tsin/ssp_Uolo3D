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

        void ResetBuffer(unsigned char *buffer);


        unique_ptr<unsigned char []> buffer_;
    };
}


#endif //UOLO3D_INDEXBUFFER_H
