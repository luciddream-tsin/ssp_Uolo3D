//
// Created by Administrator on 2022/7/1.
//

#include <fstream>
#include <cassert>
#include <iostream>
#include "StaticModel.h"
#include "IO/Log.h"
#include "GraphicsAPI/GraphicsDef.h"

namespace Uolo3D{

    StaticModel::StaticModel(Context *context) : Drawable(context){
    }

    /*
     *Model geometry and vertex morph data

      byte[4]    Identifier "UMDL"
      uint       Number of vertex buffers

        For each vertex buffer:
        uint       Vertex count
        uint       Vertex element mask (determines vertex size)
        uint       Morphable vertex range start index
        uint       Morphable vertex count
        byte[]     Vertex data (vertex count * vertex size)

      uint    Number of index buffers

        For each index buffer:
        uint       Index count
        uint       Index size (2 for 16-bit indices, 4 for 32-bit indices)
        byte[]     Index data (index count * index size)

      uint    Number of geometries

        For each geometry:
        uint       Number of bone mapping entries
        uint[]     Bone mapping data, Maps geometry bone indices to global bone indices for HW skinning.
                   May be empty, in this case identity mapping will be used.
        uint       Number of LOD levels

          For each LOD level:
          float      LOD distance
          uint       Primitive type (0 = triangle list, 1 = line list)
          uint       Vertex buffer index, starting from 0
          uint       Index buffer index, starting from 0
          uint       Draw range: index start
          uint       Draw range: index count

      uint    Number of vertex morphs (may be 0)

        For each vertex morph:
        cstring    Name of morph
        uint       Number of affected vertex buffers

          For each affected vertex buffer:
          uint       Vertex buffer index, starting from 0
          uint       Vertex element mask for morph data. Only positions, normals & tangents are supported.
          uint       Vertex count

            For each vertex:
            uint       Vertex index
            Vector3    Position (if included in the mask)
            Vector3    Normal (if included in the mask)
            Vector3    Tangent (if included in the mask)

      Skeleton data

      uint       Number of bones (may be 0)

        For each bone:
        cstring    Bone name
        uint       Parent bone index starting from 0. Same as own bone index for the root bone
        Vector3    Initial position
        Quaternion Initial rotation
        Vector3    Initial scale
        float[12]  4x3 offset matrix for skinning
        byte       Bone collision info bitmask. 1 = bounding sphere 2 = bounding box

        If bounding sphere data included:
        float      Bone radius

        If bounding box data included:
        Vector3    Bone bounding box minimum
        Vector3    Bone bounding box maximum

      Bounding box data

      Vector3    Model bounding box minimum
      Vector3    Model bounding box maximum

      Geometry center data

        For each geometry:
        Vector3    Geometry center
     *
     * */
    void StaticModel::LoadModelResource(std::string fileName) {
        std::ifstream modelFile {fileName};

        if (!modelFile.is_open()){
            UOLO3D_ERROE("file open failed!");
            return;
        }

        //read 4 characters "UMDL"
        char UMDL[5];
        modelFile.read(UMDL, 4);
        UMDL[4] = '\0';
        assert(std::string(UMDL) == "UMDL");// not support UMDL2.

        //---------------------vertex buffer------------beg-------------------------
        //read uint : Number of vertex buffers
        uint32_t numVertexBuffer;
        modelFile.read((char*)&numVertexBuffer, sizeof(numVertexBuffer));
        UOLO3D_INFO("num of vertex buffer : "+to_string(numVertexBuffer));

        //现阶段不考虑一个mdl里含有多个几何， 多个vertex buffer
        assert(numVertexBuffer == 1);
        //预先分配 capacity, 后面还是使用push_back推入.
        vertexBuffers_.reserve(numVertexBuffer);
        for (int iterVB = 0; iterVB < numVertexBuffer; ++iterVB) {
            uint32_t vertexCount = 0;
            uint32_t vertexElementMask = 0;
            uint32_t tmp_1 = 0;
            uint32_t tmp_2 = 0;

            //获得顶点数量和每个顶点包含了哪些元素类型(enum LegacyVertexElement)
            //用来计算所有顶点的大小, 也就是buffer的大小.
            modelFile.read((char*)&vertexCount, sizeof(uint32_t));
            modelFile.read((char*)&vertexElementMask, sizeof(uint32_t));
            auto vertexElements = VertexBuffer::GetElements(vertexElementMask);
            unsigned vertexSize = VertexBuffer::GetVertexSize(vertexElements);
            unsigned vertexBufferSize = vertexCount * vertexSize;

            //顶点动画相关, 跳过.
            modelFile.read((char*)&tmp_1, sizeof(uint32_t));
            modelFile.read((char*)&tmp_2, sizeof(uint32_t));

            //读取原始buffer, 并构造vertex buffer, 添加到模型vector中.
            VertexBuffer *vertexBuffer = new VertexBuffer(context_);
            unsigned char *buffer = new unsigned char [vertexBufferSize];
            modelFile.read((char*)buffer, vertexBufferSize);

            vertexBuffer->SetSize(vertexCount, vertexElements);
            vertexBuffer->ResetBuffer(buffer);
            vertexBuffers_.emplace_back(vertexBuffer);
        }

        assert(vertexBuffers_.size() == numVertexBuffer);
        //---------------------vertex buffer------------end-------------------------

        //---------------------index  buffer------------beg-------------------------
        uint32_t numIndexBuffer = 0;
        modelFile.read((char*)&numIndexBuffer, sizeof(numIndexBuffer));
        UOLO3D_INFO("num of index buffer : "+to_string(numIndexBuffer));
        assert(numIndexBuffer == 1);

        indexBuffers_.reserve(numIndexBuffer);
        for (int iterIB = 0; iterIB < numIndexBuffer; ++iterIB) {
            uint32_t indexCount = 0;
            uint32_t indexSize = 0;
            modelFile.read((char*)&indexCount, 4);
            modelFile.read((char*)&indexSize, 4);
            assert(indexCount != 0);
            assert(indexSize == 2 || indexSize == 4);//2 for 16-bit indices, 4 for 32-bit.

            IndexBuffer *indexBuffer = new IndexBuffer(context_);
            uint32_t indexBufferSize = indexCount * indexSize;
            indexBuffer->Re


            indexBuffers_.emplace_back(indexBuffer);
        }


        //---------------------index  buffer------------end-------------------------


    }

    void StaticModel::LoadMaterialResource(std::string fileName) {

    }


}