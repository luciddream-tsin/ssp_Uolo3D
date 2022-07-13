//
// Created by Administrator on 2022/6/16.
//

#ifndef UOLO3D_GRAPHICSDEF_H
#define UOLO3D_GRAPHICSDEF_H

#include <cstdint>
#include "vector"
#include "memory"
using namespace std;
namespace Uolo3D {
    class VertexBuffer;

    enum GAPI {
        GAPI_Aurora = 0, // this is a
        GAPI_OpenGL,
        GAPI_Vulkan
    };

    enum TextureUnit {
        TU_DIFFUSE = 0,
        TU_NORMAL = 1
    };
    //-------------beg---------------

    enum LegacyVertexElement{
        ELEMENT_POSITION = 0,
        ELEMENT_NORMAL,
        ELEMENT_COLOR,
        ELEMENT_TEXCOORD1,
        ELEMENT_TEXCOORD2,
        ELEMENT_CUBETEXCOORD1,
        ELEMENT_CUBETEXCOORD2,
        ELEMENT_TANGENT,
        ELEMENT_BLENDWEIGHTS,
        ELEMENT_BLENDINDICES,
        ELEMENT_INSTANCEMATRIX1,
        ELEMENT_INSTANCEMATRIX2,
        ELEMENT_INSTANCEMATRIX3,
        // Custom 32-bit integer object index. Due to API limitations, not supported on D3D9
        ELEMENT_OBJECTINDEX,
        MAX_LEGACY_VERTEX_ELEMENTS
    };

    enum VertexElementDataType{
        TYPE_INT = 0,
        TYPE_FLOAT,
        TYPE_VECTOR2,
        TYPE_VECTOR3,
        TYPE_VECTOR4,
        TYPE_UBYTE4,
        TYPE_UBYTE4_NORM,
        MAX_VERTEX_ELEMENT_TYPES
    };

    enum VertexElementSemantic{
        SEM_POSITION = 0,
        SEM_NORMAL,
        SEM_BINORMAL,
        SEM_TANGENT,
        SEM_TEXCOORD,
        SEM_COLOR,
        SEM_BLENDWEIGHTS,
        SEM_BLENDINDICES,
        SEM_OBJECTINDEX,
        MAX_VERTEX_ELEMENT_SEMANTICS
    };

    //对一中顶点类型元素的描述
    struct VertexElement{

        friend VertexBuffer;
        VertexElement() noexcept:
        dataType_(TYPE_VECTOR3), semantic_(SEM_POSITION), index_(0), offset_(0){

        }
        VertexElement(VertexElementDataType type, VertexElementSemantic semantic, uint32_t index = 0) noexcept:
        dataType_(type), semantic_(semantic), index_(index), offset_(0){

        }
    private:
        VertexElementDataType dataType_;
        VertexElementSemantic semantic_;
        uint32_t index_;
        uint32_t offset_;
    };

    extern const VertexElement LEGACY_VERTEX_ELEMENTS[];
    extern const uint32_t ELEMENT_TYPE_SIZES[];

}

#endif //UOLO3D_GRAPHICSDEF_H
