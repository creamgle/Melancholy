#pragma once
#include "Melancholy/Defines.h"
#include "Melancholy/Renderer/Shader.h"

namespace Melancholy::Platform::OpenGL {

	class OpenGL_Shader : public Shader {
	public:
		OpenGL_Shader(const std::string& vertex_source, const std::string& fragment_source);
		~OpenGL_Shader() override;

		void Bind() const override;

		void SetUniformFloat4(const std::string& name, float x, float y, float z, float w) const override;

	private:
		uint32 CreateShader(ShaderType type, const std::string& source);
		int GetUniformLocation(const std::string& name) const;

	private:
		uint32 m_Program;
	};

}
