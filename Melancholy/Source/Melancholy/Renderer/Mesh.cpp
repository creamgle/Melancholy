#include "Mesh.h"
#include "Melancholy/Platform/OpenGL/OpenGL_Mesh.h"

namespace Melancholy {

    Ref<Mesh> Mesh::Create(std::vector<Vertex> vertices, std::vector<uint32> triangles)
    {
        return CreateRef<OpenGL::OpenGL_Mesh>(vertices, triangles);
    }

}