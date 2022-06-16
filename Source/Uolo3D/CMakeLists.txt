set(UoloSources

        Core/Context.cpp
        Core/Object.cpp

        IO/Log.cpp

        Graphics/Graphics.cpp

        GraphicsAPI/OpenGL/GLGraphics.cpp
        GraphicsAPI/OpenGL/GLGraphicsImpl.h

        Engine/Application.cpp
        Engine/Engine.cpp
        )
add_library(Uolo3D ${UoloSources})

target_link_libraries(Uolo3D SDL2d)