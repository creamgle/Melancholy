#pragma once
#include "Melancholy/Renderer/Shader.h"

namespace Melancholy::OpenGL {

    class OpenGL_Shader : public Shader {
    public:
        OpenGL_Shader(const std::string& vertex, const std::string& fragment);
        ~OpenGL_Shader() override;

        void Bind() override;

        void SetUniformFloat4(const std::string& name, float x, float y, float z, float w) override;

        void SetUniformMatrix4(const std::string& name, const Matrix4& value) override;

    private:
        uint32 LoadShader(uint32 type, const std::string& source);
        uint32 GetUniformLocation(const std::string& name);

    private:
        uint32 mProgram;
    };

}