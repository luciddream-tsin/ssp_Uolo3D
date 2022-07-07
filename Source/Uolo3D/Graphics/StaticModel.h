//
// Created by Administrator on 2022/7/1.
//

#ifndef UOLO3D_STATICMODEL_H
#define UOLO3D_STATICMODEL_H


#include "Drawable.h"
#include "Model.h"

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
        std::shared_ptr<Model> model_;


    };
}


#endif //UOLO3D_STATICMODEL_H
