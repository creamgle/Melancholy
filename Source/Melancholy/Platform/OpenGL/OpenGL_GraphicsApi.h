#pragma once
#include "Melancholy/Renderer/GraphicsApi.h"

namespace Melancholy::Platform::OpenGL {

	class OpenGL_GraphicsApi : public GraphicsApi{
	public:
		OpenGL_GraphicsApi() = default;
		~OpenGL_GraphicsApi() override = default;

		void Clear() override;

		void SetClearColor(float r, float g, float b, float a) override;
	};

}