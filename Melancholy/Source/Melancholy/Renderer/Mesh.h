#pragma once
#include "Melancholy/Core.h"
#include "Melancholy/Core/Math.h"
#include <vector>

namespace Melancholy {

    struct Vertex {
        Vector3 Position;
        Vector3 Normal = { 0, 0, 0 };
        Vector2 TexCoord { 0, 0 };
    };

    MAPI class Mesh {
    public:
        virtual ~Mesh() = default;

        static Ref<Mesh> Create(std::vector<Vertex> vertices, std::vector<uint32> triangles);

        virtual void Draw() = 0;
    };

}