set(UoloSources

        Core/Context.cpp
        Core/Object.cpp

        IO/Log.cpp

        Graphics/Graphics.cpp
        Graphics/Renderer.cpp

        GraphicsAPI/OpenGL/GLGraphics.cpp
        GraphicsAPI/OpenGL/GLGraphicsImpl.h

        Engine/Application.cpp
        Engine/Engine.cpp
        )
add_library(Uolo3D ${UoloSources})

#windows mingw
#target_link_libraries(Uolo3D glew32 opengl32 SDL2d)

#linux
target_link_libraries(Uolo3D GL SDL2-2.0d GLEW)