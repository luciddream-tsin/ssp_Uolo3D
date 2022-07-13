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
        // FIXME : 功能完成，但数据又误, 待修改.

        std::ifstream modelFStream {fileName};
        if (!modelFStream.is_open()){
            UOLO3D_ERROE("file open failed!");
            return;
        }

        //read 4 characters "UMDL"
        {
            char UMDL[5];
            modelFStream.read(UMDL, 4);
            UMDL[4] = '\0';
            assert(std::string(UMDL) == "UMDL");// not support UMDL2.
        }

        //---------------------vertex buffer------------beg-------------------------
        {
            //read uint : Number of vertex buffers
            uint32_t numVertexBuffers;
            modelFStream.read((char *) &numVertexBuffers, sizeof(numVertexBuffers));
            UOLO3D_INFO("num of vertex buffer : " + to_string(numVertexBuffers));

            //现阶段不考虑一个mdl里含有多个几何， 多个vertex buffer
            assert(numVertexBuffers == 1);
            //预先分配 capacity, 后面还是使用push_back推入.
            vertexBuffers_.reserve(numVertexBuffers);
            for (int iterVB = 0; iterVB < numVertexBuffers; ++iterVB) {
                uint32_t vertexCount = 0;
                uint32_t vertexElementMask = 0;
                uint32_t tmp_1 = 0;
                uint32_t tmp_2 = 0;

                //获得顶点数量和每个顶点包含了哪些元素类型(enum LegacyVertexElement)
                //用来计算所有顶点的大小, 也就是buffer的大小.
                modelFStream.read((char *) &vertexCount, sizeof(uint32_t));
                modelFStream.read((char *) &vertexElementMask, sizeof(uint32_t));
                auto vertexElements = VertexBuffer::GetElements(vertexElementMask);
                unsigned vertexSize = VertexBuffer::GetVertexSize(vertexElements);
                unsigned vertexBufferSize = vertexCount * vertexSize;

                //顶点动画相关, 跳过.
                modelFStream.read((char *) &tmp_1, sizeof(uint32_t));
                modelFStream.read((char *) &tmp_2, sizeof(uint32_t));

                //读取原始buffer, 并构造vertex buffer, 添加到模型vector中.
                VertexBuffer *vertexBuffer = new VertexBuffer(context_);
                unsigned char *buffer = new unsigned char[vertexBufferSize];
                modelFStream.read((char *) buffer, vertexBufferSize);

                vertexBuffer->SetSize(vertexCount, vertexElements);
                vertexBuffer->ResetBuffer(buffer);
                vertexBuffers_.emplace_back(vertexBuffer);
            }

            assert(vertexBuffers_.size() == numVertexBuffers);
        }
        //---------------------vertex buffer------------end-------------------------

        //---------------------index  buffer------------beg-------------------------
        {
            uint32_t numIndexBuffers = 0;
            modelFStream.read((char *) &numIndexBuffers, sizeof(numIndexBuffers));
            UOLO3D_INFO("num of index buffer : " + to_string(numIndexBuffers));
            assert(numIndexBuffers == 1);

            indexBuffers_.reserve(numIndexBuffers);
            for (int iterIB = 0; iterIB < numIndexBuffers; ++iterIB) {
                uint32_t indexCount = 0;
                uint32_t indexSize = 0;
                modelFStream.read((char *) &indexCount, 4);
                modelFStream.read((char *) &indexSize, 4);
                assert(indexCount != 0);
                assert(indexSize == 2 || indexSize == 4);//2 for 16-bit indices, 4 for 32-bit.

                IndexBuffer *indexBuffer = new IndexBuffer(context_);
                uint32_t indexBufferSize = indexCount * indexSize;

                unsigned char *buffer = new unsigned char[indexBufferSize];
                modelFStream.read((char *) buffer, indexBufferSize);
                indexBuffer->ResetBuffer(buffer);
                indexBuffer->SetSize(indexCount, indexSize);
                indexBuffers_.emplace_back(indexBuffer);
            }
        }
        //---------------------index  buffer------------end-------------------------

        //---------------------geometries---------------beg-------------------------
        {
            uint32_t numGeometries = 0;
            modelFStream.read((char *) &numGeometries, sizeof(uint32_t));
            assert(numGeometries > 0);
            geometries_.reserve(numGeometries);
            geometryCenters_.reserve(numGeometries);
            for (int iterGeo = 0; iterGeo < numGeometries; ++iterGeo) {

                //bone mapping, ignore...
                uint32_t numBoneMapping = 0;
                modelFStream.read((char *) &numBoneMapping, sizeof(uint32_t));
                for (int i = 0; i < numBoneMapping; ++i) {
                    uint32_t tmpUInt = 0;
                    modelFStream.read((char *) &tmpUInt, sizeof(uint32_t));
                }

                //LOD, 注意目前我们只要第一级的LOD其他的丢弃.
                uint32_t numLODLevels = 0;
                modelFStream.read((char *) &numLODLevels, sizeof(uint32_t));
                assert(numLODLevels > 0);
                for (int i = 0; i < numLODLevels; ++i) {
                    // 在次强调， 我们目前只要第一级的LOD数据, 其他的读取丢掉.
                    Geometry *geometry = new Geometry(context_);

                    float &distanceLOD = geometry->distanceLOD_;
                    uint32_t &primitiveType = geometry->primitiveType_;
                    uint32_t &vbRef = geometry->vbRef_;
                    uint32_t &ibRef = geometry->ibRef_;
                    uint32_t &indexStart = geometry->indexStart_;
                    uint32_t &indexCount = geometry->indexCount_;

                    modelFStream.read((char *) &distanceLOD, sizeof(distanceLOD));
                    modelFStream.read((char *) &primitiveType, sizeof(primitiveType));
                    modelFStream.read((char *) &vbRef, sizeof(vbRef));
                    modelFStream.read((char *) &ibRef, sizeof(ibRef));
                    modelFStream.read((char *) &indexStart, sizeof(indexStart));
                    modelFStream.read((char *) &indexCount, sizeof(indexCount));

                    if (vbRef >= vertexBuffers_.size()) {
                        UOLO3D_ERROE("Vertex buffer index out of bounds");
                        return;
                    }
                    if (ibRef >= indexBuffers_.size()) {
                        UOLO3D_ERROE("Index buffer index out of bounds");
                        return;
                    }


                    if (i == 0) {// 在次强调， 我们目前只要第一级的LOD数据, 其他的读取丢掉.
                        geometries_.emplace_back(geometry);
                    } else {
                        delete geometry;
                    }
                }
            }
        }
        //---------------------geometries---------------end-------------------------


        //---------------------vertex morphs------------beg-------------------------
        {
            uint32_t numVertexMorphs = 0;
            modelFStream.read((char*)&numVertexMorphs, sizeof (numVertexMorphs));
            for (int iterVM = 0; iterVM < numVertexMorphs; ++iterVM) {
                // TODO : 现在这个模型没有vertex morph, 暂时这样, 但是get_line获取字符串有可能不对.
                std::string morphName = "";
                std::getline(modelFStream, morphName);
                uint32_t numImpactedVB = 0;
                modelFStream.readsome((char*)&numImpactedVB, sizeof (numImpactedVB));
                for (int i = 0; i < numImpactedVB; ++i) {
                    uint32_t vertexBufferIndex = 0;
                    uint32_t vertexElementMask = 0;
                    uint32_t vertexCount = 0;
                    modelFStream.read((char*)&vertexBufferIndex, sizeof (uint32_t));
                    modelFStream.read((char*)&vertexElementMask, sizeof (uint32_t));
                    modelFStream.read((char*)&vertexCount, sizeof (uint32_t));

                    // 每一个顶点的大小
                    // TODO: 检查 vertexSize += sizeof (mathfu::Vector<uint32_t , 3>);
                    uint32_t vertexSize = sizeof(uint32_t);
                    if (vertexElementMask & MASK_POSITION){
                        vertexSize += sizeof (mathfu::Vector<uint32_t , 3>);
                    }
                    if (vertexElementMask & MASK_NORMAL){
                        vertexSize += sizeof (mathfu::Vector<uint32_t , 3>);
                    }
                    if (vertexElementMask & MASK_TANGENT){
                        vertexSize += sizeof (mathfu::Vector<uint32_t , 3>);
                    }

                    char * tmpVertex = new char[vertexSize];
                    modelFStream.read(tmpVertex, vertexSize);
                }
            }
        }
        //---------------------vertex morphs------------end-------------------------

        //---------------------skeleton data------------beg-------------------------
        {
            //没有骨骼先跳过
            uint32_t numBones = 0;
            modelFStream.read((char *) &numBones, sizeof(numBones));
            assert(numBones == 0);
        }
        //---------------------skeleton data------------end-------------------------

        //---------------------bounding box-------------beg-------------------------
        {
            vf3 minBox;
            vf3 maxBox;
            modelFStream.read((char*)&minBox, sizeof (minBox));
            modelFStream.read((char*)&maxBox, sizeof (maxBox));
            boundingBox_ = BoundingBox(minBox, maxBox);
        }
        //---------------------bounding box-------------end-------------------------

        //---------------------geometry center----------beg-------------------------
        {
            for (int numGC = 0; numGC < geometryCenters_.capacity(); ++numGC) {
                vf3 geometryCenter;
                modelFStream.read((char*)&geometryCenter, sizeof (geometryCenter));
                geometryCenters_.push_back(geometryCenter);
            }
        }
        //---------------------geometry center----------end-------------------------
    }

    void StaticModel::LoadMaterialResource(std::string fileName) {

    }


}