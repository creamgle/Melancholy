#pragma once
#include "Melancholy/Core.h"
#include "Melancholy/Renderer/Mesh.h"
#include <vector>

namespace Melancholy::OpenGL {

    class OpenGL_Mesh : public Mesh {
    public:
        OpenGL_Mesh(std::vector<Vertex> vertices, std::vector<uint32> triangles);
        ~OpenGL_Mesh() override;

        void Draw() override;

    private:
        std::vector<Vertex> mVertices;
        std::vector<uint32> mTriangles;

        uint32 mVao;
    };

}