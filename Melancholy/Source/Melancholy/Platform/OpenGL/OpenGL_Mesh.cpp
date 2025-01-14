#include "OpenGL_Mesh.h"
#include "Melancholy/Renderer/Mesh.h"
#include <glad/glad.h>
#include <vector>

namespace Melancholy::OpenGL {

    OpenGL_Mesh::OpenGL_Mesh(std::vector<Vertex> vertices, std::vector<uint32> triangles)
        : mVertices(vertices), mTriangles(triangles)
    {
        uint32 vbo, ebo;

        glGenVertexArrays(1, &mVao);
        glBindVertexArray(mVao);

        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(Vertex), &mVertices[0], GL_STATIC_DRAW);

        glGenBuffers(1, &ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, mTriangles.size() * sizeof(uint32), &mTriangles[0], GL_STATIC_DRAW);

        /* Position */
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position));

        /* Normal */
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));

        /* Texture Coords */
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoord));

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    OpenGL_Mesh::~OpenGL_Mesh()
    {
        glDeleteVertexArrays(1, &mVao);
    }

    void OpenGL_Mesh::Draw()
    {
        glBindVertexArray(mVao);
        glDrawElements(GL_TRIANGLES, mTriangles.size(), GL_UNSIGNED_INT, 0);
    }

}