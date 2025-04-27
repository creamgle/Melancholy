#include "Mesh.h"

#include <Melancholy/Platform/OpenGL/OpenGL_Mesh.h>

namespace Melancholy {

	Mesh* Mesh::Create(const std::vector<Vertex>& vertices, const std::vector<uint32>& triangles)
	{
		return new Platform::OpenGL::OpenGL_Mesh(vertices, triangles);
	}

}