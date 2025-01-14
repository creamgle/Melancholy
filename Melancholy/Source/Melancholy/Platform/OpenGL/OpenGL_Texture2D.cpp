#include "OpenGL_Texture2D.h"
#include "Melancholy/Renderer/Texture2D.h"
#include <glad/glad.h>

namespace Melancholy::OpenGL {

    OpenGL_Texture2D::OpenGL_Texture2D(uint32 width, uint32 height, uint8* data, TextureFormat format, TextureFilter filter)
        : mFormat(format), mWidth(width), mHeight(height)
    {
        glGenTextures(1, &mTextureID);
        glBindTexture(GL_TEXTURE_2D, mTextureID);

        // Convertes enum values to OpenGL integer definitions
        uint32 glFilter = filter == TextureFilter::Nearest ? GL_NEAREST : GL_LINEAR;
        uint32 glFilterMipmap = filter == TextureFilter::Nearest ? GL_NEAREST_MIPMAP_NEAREST : GL_LINEAR_MIPMAP_LINEAR;
        uint32 glFormat = mFormat == TextureFormat::RGB ? GL_RGB : GL_RGBA;
        uint32 glFormatInternal = mFormat == TextureFormat::RGB ? GL_RGB8 : GL_RGBA8;

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, glFilterMipmap);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, glFilter);

        glTexImage2D(GL_TEXTURE_2D, 0, glFormatInternal, mWidth, mHeight, 0, glFormat, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, 0);
    }

    OpenGL_Texture2D::~OpenGL_Texture2D()
    {
        glDeleteTextures(1, &mTextureID);
    }

    void OpenGL_Texture2D::Bind(uint32 slot)
    {
        // TODO: maybe check slot if its too big and limit it
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, mTextureID);
    }

}