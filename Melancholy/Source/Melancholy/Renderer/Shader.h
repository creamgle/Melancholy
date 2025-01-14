#pragma once
#include "Melancholy/Core.h"
#include <string>

namespace Melancholy {

    struct Matrix4;

    MAPI class Shader {
    public:
        virtual ~Shader() = default;

        static Ref<Shader> Create(const std::string& vertex, const std::string& fragment);

        virtual void Bind() = 0;

        virtual void SetUniformFloat4(const std::string& name, float x, float y, float z, float w) = 0;

        virtual void SetUniformMatrix4(const std::string& name, const Matrix4& value) = 0;
    };

}