#pragma once
#include "Melancholy/Defines.h"
#include "Melancholy/Core/Math.h"
#include <vector>


namespace Melancholy {

	struct Vertex {
		Vector3 Position;
		Vector4 Color = { 1.0f, 1.0f, 1.0f, 1.0f };
	};

	class Mesh {
	public:
		virtual ~Mesh() = default;

		static Mesh* Create(const std::vector<Vertex>& vertices, const std::vector<uint32>& triangles);

		virtual void Draw() const = 0;
	};

}
