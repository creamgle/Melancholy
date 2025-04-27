#include "OpenGL_Mesh.h"
#include <glad/glad.h>

#include "Melancholy/Core/Logger.h"

namespace Melancholy::Platform::OpenGL {

	OpenGL_Mesh::OpenGL_Mesh(const std::vector<Vertex>& vertices, const std::vector<uint32>& triangles)
	{
		m_TriangleCount = triangles.size();

		glGenVertexArrays(1, &m_Vao);
		glBindVertexArray(m_Vao);

		uint32 vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

		/* Position */
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0L);

		/* Color */
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Color));

		uint32 ebo;
		glGenBuffers(1, &ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, triangles.size() * sizeof(uint32), triangles.data(), GL_STATIC_DRAW);

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		MTRACE("Created OpenGL Mesh: [Vao: {} TriCount: {}]", m_Vao, m_TriangleCount);
	}

	OpenGL_Mesh::~OpenGL_Mesh()
	{
		glDeleteVertexArrays(1, &m_Vao);
	}

	void OpenGL_Mesh::Draw() const
	{
		glBindVertexArray(m_Vao);
		glDrawElements(GL_TRIANGLES, m_TriangleCount, GL_UNSIGNED_INT, 0);
	}

}
