#include "GraphicsApi.h"

#include "Melancholy/Platform/OpenGL/OpenGL_GraphicsApi.h"

namespace Melancholy {

	GraphicsApi* GraphicsApi::Create()
	{
		return new Platform::OpenGL::OpenGL_GraphicsApi();
	}

}
