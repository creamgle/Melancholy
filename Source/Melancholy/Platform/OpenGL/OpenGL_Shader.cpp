#include "OpenGL_Shader.h"
#include "Melancholy/Core/Logger.h"
#include <glad/glad.h>

namespace Melancholy::Platform::OpenGL {

#define SHADER_CREATE_ERROR (int)(-1)

	OpenGL_Shader::OpenGL_Shader(const std::string& vertex_source, const std::string& fragment_source)
	{
		uint32 vertex = CreateShader(ShaderType::Vertex, vertex_source);
		uint32 fragment = CreateShader(ShaderType::Fragment, fragment_source);

		if (vertex == SHADER_CREATE_ERROR || fragment == SHADER_CREATE_ERROR)
		{
			MERROR("Shader compilation failed check above^ for more info!");
			return;
		}

		m_Program = glCreateProgram();

		glAttachShader(m_Program, vertex);
		glAttachShader(m_Program, fragment);

		glLinkProgram(m_Program);
		glValidateProgram(m_Program);

		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	OpenGL_Shader::~OpenGL_Shader()
	{
		glDeleteProgram(m_Program);
	}

	void OpenGL_Shader::Bind() const
	{
		glUseProgram(m_Program);
	}

	void OpenGL_Shader::SetUniformFloat4(const std::string& name, float x, float y, float z, float w) const
	{
		glUniform4f(GetUniformLocation(name), x, y, z, w);
	}


	uint32 OpenGL_Shader::CreateShader(ShaderType type, const std::string& source)
	{
		uint32 glType = type == ShaderType::Vertex ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER;
		const char* sourceCStr = source.c_str();

		uint32 shader = glCreateShader(glType);
		glShaderSource(shader, 1, &sourceCStr, NULL);
		glCompileShader(shader);

		int success;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			// I dont know how good this is, but ai did this cause i dont
			// feel like dealing with opengl shader error messaging again D:<
			int length;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
			glGetShaderInfoLog(shader, length, NULL, NULL);
			std::string infoLog;
			infoLog.resize(length);
			glGetShaderInfoLog(shader, length, NULL, &infoLog[0]);

			std::string typeString = type == ShaderType::Vertex ? "Vertex" : "Fragment";
			MFATAL("Failed to compile OpenGL shader type: {}", typeString);
			MFATAL("{}", infoLog);

			return SHADER_CREATE_ERROR;
		}

		return shader;
	}

	int OpenGL_Shader::GetUniformLocation(const std::string& name) const
	{
		return glGetUniformLocation(m_Program, name.c_str());
	}

}
