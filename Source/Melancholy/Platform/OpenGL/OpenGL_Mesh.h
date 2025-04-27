#pragma once
#include "Melancholy/Renderer/Mesh.h"

namespace Melancholy::Platform::OpenGL {

	class OpenGL_Mesh : public Mesh {
	public:
		OpenGL_Mesh(const std::vector<Vertex>& vertices, const std::vector<uint32>& triangles);
		~OpenGL_Mesh() override;

		void Draw() const override;

	private:
		uint32 m_Vao;
		uint32 m_TriangleCount;
	};

}
