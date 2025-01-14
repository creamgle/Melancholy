#include "OpenGL_Shader.h"
#include "Melancholy/Core.h"
#include "Melancholy/Core/Math.h"
#include <glad/glad.h>

namespace Melancholy::OpenGL {

    OpenGL_Shader::OpenGL_Shader(const std::string& vertex, const std::string& fragment)
    {
        uint32 vert = LoadShader(GL_VERTEX_SHADER, vertex);
        uint32 frag = LoadShader(GL_FRAGMENT_SHADER, fragment);

        if (vert == 0 || frag == 0)
        {
            MERROR("OpenGL Shader Creating Failure!");
            return;
        }

        mProgram = glCreateProgram();
        glAttachShader(mProgram, vert);
        glAttachShader(mProgram, frag);

        glLinkProgram(mProgram);

        char infoLog[512];
        int success;
        glGetProgramiv(mProgram, GL_LINK_STATUS, &success);
        if(!success)
        {
            glGetProgramInfoLog(mProgram, 512, NULL, infoLog);
            MERROR("OpenGL Shader Program Linking Error: {}", infoLog);
        }
        
        glDeleteShader(vert);
        glDeleteShader(frag);
    }

    OpenGL_Shader::~OpenGL_Shader()
    {
        glDeleteProgram(mProgram);
    }

    void OpenGL_Shader::Bind()
    {
        glUseProgram(mProgram);
    }

    void OpenGL_Shader::SetUniformFloat4(const std::string& name, float x, float y, float z, float w)
    {
        glUniform4f(GetUniformLocation(name), x, y, z, w);
    }

    void OpenGL_Shader::SetUniformMatrix4(const std::string& name, const Matrix4& value)
    {
        glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &value.m[0]);
    }

    uint32 OpenGL_Shader::LoadShader(uint32 type, const std::string& source)
    {
        char infoLog[512];
        const char* sourceCStr = source.c_str();

        uint32 shader = glCreateShader(type);
        glShaderSource(shader, 1, &sourceCStr, NULL);
        glCompileShader(shader);

        int success = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            std::string typeString = "INVALID_SHADER_TYPE";
            if (type == GL_VERTEX_SHADER) typeString = "Vertex";
            else if (type == GL_FRAGMENT_SHADER) typeString = "Fragment";

            glGetShaderInfoLog(shader, 512, NULL, infoLog);
            MERROR("OpenGL [{}] Shader Compile Error: {}", typeString, infoLog);
            return 0;
        }

        return shader;
    }

    uint32 OpenGL_Shader::GetUniformLocation(const std::string& name)
    {
        return glGetUniformLocation(mProgram, name.c_str());
    }

}