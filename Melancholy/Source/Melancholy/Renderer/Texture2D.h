#pragma once
#include "Melancholy/Core.h"

namespace Melancholy {

    enum class TextureFormat {
        RGB,    // No alpha component
        RGBA,   // Alpha component
    };

    enum class TextureFilter {
        Nearest,
        Linear
    };

    MAPI class Texture2D {
    public:
        virtual ~Texture2D() = default;

        static Ref<Texture2D> Load(const std::string& path, TextureFilter filter = TextureFilter::Nearest);
        static Ref<Texture2D> Create(uint32 width, uint32 height, uint8* data, TextureFormat format, TextureFilter filter);

        virtual void Bind(uint32 slot) = 0;
    };

}