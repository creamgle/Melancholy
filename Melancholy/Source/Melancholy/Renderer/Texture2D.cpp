#include "Texture2D.h"
#include "Melancholy/Platform/OpenGL/OpenGL_Texture2D.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace Melancholy {

    Ref<Texture2D> Texture2D::Load(const std::string& path, TextureFilter filter)
    {
        int width, height, compoenents;

        stbi_set_flip_vertically_on_load(true);
        uint8* data = stbi_load(path.c_str(), &width, &height, &compoenents, 0);
        if (!data)
        {
            MERROR("Failed to load image [{}]! (support for a fallback image will be added soon :D)", path);
        }

        TextureFormat format = TextureFormat::RGB;
        if (compoenents == 4)
            format = TextureFormat::RGBA;


        return Create(width, height, data, format, filter);
    }

    Ref<Texture2D> Texture2D::Create(uint32 width, uint32 height, uint8* data, TextureFormat format, TextureFilter filter)
    {
        return CreateRef<OpenGL::OpenGL_Texture2D>(width, height, data, format, filter);
    }

}