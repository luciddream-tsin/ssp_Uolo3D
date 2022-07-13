//
// Created by Administrator on 2022/7/13.
//

#include "VertexBuffer.h"
#include "GraphicsDef.h"
#include "vector"

namespace Uolo3D{
    VertexBuffer::VertexBuffer(Context *context) : Object(context) {
        buffer_.reset(nullptr);
    }
    vector<VertexElement> VertexBuffer::GetElements(uint32_t elementMask) {
        vector<VertexElement> ret;
        for (int iterEM = 0; iterEM < MAX_LEGACY_VERTEX_ELEMENTS; ++iterEM) {
            if (elementMask & (1u << iterEM)){
                ret.push_back(LEGACY_VERTEX_ELEMENTS[iterEM]);
            }
        }
        return ret;
    }

    uint32_t VertexBuffer::GetVertexSize(vector<VertexElement>& vertexElements) {

        uint32_t size = 0;
        for (int i = 0; i < vertexElements.size(); ++i) {
            size += ELEMENT_TYPE_SIZES[vertexElements[i].dataType_];
        }
        return size;
    }

    void VertexBuffer::SetSize(uint32_t vertexCount, vector<VertexElement>& vertexElements) {
        this->vertexCount_ = vertexCount;
        this->vertexElements_ = vertexElements;
    }

    void VertexBuffer::ResetBuffer(unsigned char *buffer) {
        this->buffer_.reset(buffer);
    }

}