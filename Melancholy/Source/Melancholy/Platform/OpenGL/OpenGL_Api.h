#pragma once
#include "Melancholy/Core.h"
#include "Melancholy/Renderer/GraphicsApi.h"

namespace Melancholy::OpenGL {

    class OpenGL_Api : public GraphicsApi {
    public:
        OpenGL_Api() = default;
        ~OpenGL_Api() override = default;

        void Clear() override;

        void SetClearColor(float r, float g, float b, float a) override;
    };

}