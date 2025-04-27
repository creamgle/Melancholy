#pragma once
#include <string>

namespace Melancholy {

	enum class ShaderType {
		Vertex,
		Fragment
	};

	class Shader {
	public:
		virtual ~Shader() = default;

		static Shader* Create(const std::string& vertex_source, const std::string& fragment_source);

		virtual void Bind() const = 0;

		virtual void SetUniformFloat4(const std::string& name, float x, float y, float z, float w) const = 0;
	};

}
