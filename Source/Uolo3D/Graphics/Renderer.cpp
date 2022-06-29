//
// Created by Administrator on 2022/6/15.
//

#include "Renderer.h"
#include "GL/glew.h"


namespace Uolo3D{
    Renderer::Renderer(Context *context) : Object(context){

    }

    void Renderer::Update() {
        //tmp 临时的 SDL swap 测试 -------beg----------
        float r = rand() / 100000.0;
        float g = rand() / 100000.0;
        float b = rand() / 100000.0;
        float c = rand() / 100000.0;
        if (c < 0.01){
            r =g =b = 255;
        }
        glClearColor(r , g, b, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //tmp 临时的 SDL swap 测试 -------end----------

    }

}