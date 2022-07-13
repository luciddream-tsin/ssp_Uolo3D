//
// Created by Administrator on 2022/7/13.
//

#ifndef UOLO3D_VERTEXBUFFER_H
#define UOLO3D_VERTEXBUFFER_H

#include "Core/Object.h"
#include "vector"

namespace Uolo3D {
    struct VertexElement;

    class VertexBuffer : public Object{
        UOLO3D_CLASS_INFO(VertexBuffer, Object)
    public:
        VertexBuffer() = delete;
        VertexBuffer(Context *context);

        static vector<VertexElement> GetElements(uint32_t elementMask);
        static uint32_t GetVertexSize(vector<VertexElement>& vertexElements);

        void SetSize(uint32_t vertexCount, vector<VertexElement>& vertexElements);
        void ResetBuffer(unsigned char *buffer);


    private:
        uint32_t vertexCount_;
        vector<VertexElement> vertexElements_;
        // 对数组来说，假如unique_ptr的尖括号<>包括的类型是数组, 则即使没有明确指明deleter ,
        // unique_ptr销毁时，数组仍会以delete []的方式释放, 切记: shared_ptr不可以这样做.
        unique_ptr<unsigned char[]> buffer_;
    };
}


#endif //UOLO3D_VERTEXBUFFER_H
