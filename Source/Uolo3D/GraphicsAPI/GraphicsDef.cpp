//
// Created by Administrator on 2022/7/13.
//

#include "GraphicsDef.h"

namespace Uolo3D {

    const VertexElement LEGACY_VERTEX_ELEMENTS[] = {
            VertexElement(TYPE_VECTOR3, SEM_POSITION, 0),     // Position
            VertexElement(TYPE_VECTOR3, SEM_NORMAL, 0 ),     // Normal
            VertexElement(TYPE_UBYTE4_NORM, SEM_COLOR, 0),    // Color
            VertexElement(TYPE_VECTOR2, SEM_TEXCOORD, 0),     // Texcoord1
            VertexElement(TYPE_VECTOR2, SEM_TEXCOORD, 1),     // Texcoord2
            VertexElement(TYPE_VECTOR3, SEM_TEXCOORD, 0),     // Cubetexcoord1
            VertexElement(TYPE_VECTOR3, SEM_TEXCOORD, 1),     // Cubetexcoord2
            VertexElement(TYPE_VECTOR4, SEM_TANGENT, 0),      // Tangent
            VertexElement(TYPE_VECTOR4, SEM_BLENDWEIGHTS, 0), // Blendweights
            VertexElement(TYPE_UBYTE4, SEM_BLENDINDICES, 0),  // Blendindices
            VertexElement(TYPE_VECTOR4, SEM_TEXCOORD, 4),     // Instancematrix1
            VertexElement(TYPE_VECTOR4, SEM_TEXCOORD, 5),      // Instancematrix2
            VertexElement(TYPE_VECTOR4, SEM_TEXCOORD, 6),      // Instancematrix3
            VertexElement(TYPE_INT, SEM_OBJECTINDEX, 0)       // Objectindex
    };
    const uint32_t ELEMENT_TYPE_SIZES[] = {
            sizeof(int),
            sizeof(float),
            2 * sizeof(float),
            3 * sizeof(float),
            4 * sizeof(float),
            sizeof(unsigned),
            sizeof(unsigned)
    };
}