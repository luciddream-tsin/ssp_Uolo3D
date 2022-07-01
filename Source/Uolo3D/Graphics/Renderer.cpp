//
// Created by Administrator on 2022/6/15.
//

#include "Renderer.h"
#include "Core/Context.h"
#include "Graphics.h"
#include "GL/glew.h"


namespace Uolo3D{
    Renderer::Renderer(Context *context) : Object(context){

    }

    void Renderer::Update() {
        context_->GetSubsystem<Graphics>()->Draw_GL();
    }

    void Renderer::SetViewport(int index, Viewport *viewport) {

    }

}