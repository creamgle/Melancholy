#pragma once
#include "Melancholy/Core.h"
#include "Melancholy/Renderer/Texture2D.h"

namespace Melancholy::OpenGL {

    class OpenGL_Texture2D : public Texture2D {
    public:
        OpenGL_Texture2D(uint32 width, uint32 height, uint8* data, TextureFormat format, TextureFilter filter);
        ~OpenGL_Texture2D() override;

        void Bind(uint32 slot) override;

    private:
        TextureFormat mFormat;
        uint32 mWidth, mHeight;
        uint32 mTextureID;
    };

}