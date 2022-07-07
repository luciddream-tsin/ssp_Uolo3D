//
// Created by Administrator on 2022/7/7.
//

#ifndef UOLO3D_MATERIAL_H
#define UOLO3D_MATERIAL_H

#include <vector>
#include <map>
#include "Resource/TmpResource.h"
#include "GraphicsAPI/GraphicsDef.h"
#include "Technique.h"

namespace Uolo3D {
    class Texture;

    struct MaterialShaderParameter{
        std::string name;
        params_union value;
    };

    class Material : public TmpResource{
        UOLO3D_CLASS_INFO(Material, TmpResource)
    public:
        Material() = delete;
        Material(Context *context);


    private:
        //目前先添加Stone.xml材质的解析项目
        std::string vxShaderDefines_; // vertex shader defines.
        std::string pxShaderDefines_; // pixel  shader defines.

        std::vector<Technique> techniques_;
        std::map<TextureUnit, std::shared_ptr<Texture>> textures_;
        std::map<strHash, MaterialShaderParameter> shaderParameters_;
    };
}


#endif //UOLO3D_MATERIAL_H
