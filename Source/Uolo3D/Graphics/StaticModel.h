//
// Created by Administrator on 2022/7/1.
//

#ifndef UOLO3D_STATICMODEL_H
#define UOLO3D_STATICMODEL_H


#include "Drawable.h"
#include "Model.h"
#include "GraphicsAPI/VertexBuffer.h"
#include "GraphicsAPI/IndexBuffer.h"
#include "Geometry.h"
#include "mathfu/vector.h"
#include "vector"

namespace Uolo3D {
    class StaticModel : public Drawable{
        UOLO3D_CLASS_INFO(StaticModel, Drawable)
    public:
        StaticModel() = delete;
        StaticModel(Context *context);

        //-------------------------------------------------------------
        //暂时不添加SetModel(ResourceCache<Model>->GetResource())这个API ,
        //这个是通过ResourceCache这个专门的系统加载资源.
        //我们现在直接在StaticModel 这个"Component" 中读取文件系统里的资源.
        void LoadModelResource(std::string fileName);
        void LoadMaterialResource(std::string fileName);
        //-------------------------------------------------------------

    private:
        //TODO: 检测有没有使用原则: shared_ptr不share, weak_ptr不weak
        //geometries_不是二维vector, 因为现在不支持LOD
        vector<shared_ptr<VertexBuffer>> vertexBuffers_;
        vector<shared_ptr<IndexBuffer>> indexBuffers_;
        vector<shared_ptr<Geometry>> geometries_;

        vector<mathfu::Vector<int, 3>> geometryCenters_;

    };
}


#endif //UOLO3D_STATICMODEL_H
