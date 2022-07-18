set(UoloSources

        #-----------Core--------
        Core/Context.cpp
        Core/Object.cpp
        Core/Timer.cpp

        #------------IO---------
        IO/Log.cpp

        #----------Scene--------
        Scene/Scene.cpp
        Scene/Node.cpp
        Scene/Component.cpp

        #---------Graphics------
        Graphics/Graphics.cpp
        Graphics/Renderer.cpp
        Graphics/Drawable.cpp
        Graphics/StaticModel.cpp
        Graphics/Light.cpp
        Graphics/Camera.cpp
        Graphics/Viewport.cpp
        Graphics/Model.cpp
        Graphics/Material.cpp
        Graphics/Geometry.cpp
        Graphics/Technique.cpp
        Graphics/Octree.cpp
        Graphics/RenderPath.cpp
        Graphics/View.cpp
        Graphics/Batch.cpp

        #----------GraphicsAPI---
        GraphicsAPI/OpenGL/GLGraphics.cpp
        GraphicsAPI/OpenGL/GLGraphicsImpl.h
        GraphicsAPI/Texture.cpp
        GraphicsAPI/IndexBuffer.cpp
        GraphicsAPI/VertexBuffer.cpp
        GraphicsAPI/GraphicsDef.cpp

        #----------Math----------
        Math/BoundingBox.cpp


        #----------Resource------
        Resource/TmpResource.cpp

        #----------Engine--------
        Engine/Application.cpp
        Engine/Engine.cpp

        )
add_library(Uolo3D ${UoloSources})

#windows mingw
target_link_libraries(Uolo3D glew32 opengl32 SDL2d)

#linux
#target_link_libraries(Uolo3D GL SDL2-2.0d GLEW)