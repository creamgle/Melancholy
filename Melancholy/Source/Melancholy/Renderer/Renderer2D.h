#pragma once
#include "Melancholy/Core.h"
#include "Melancholy/Renderer/GraphicsApi.h"

namespace Melancholy::Renderer2D {

	MAPI bool Initialise();
	MAPI void Destroy();

	MAPI void Clear();

	MAPI void SetBackgroundColor(float r, float g, float b, float a);

	MAPI Scope<GraphicsApi> GetGraphicsApi();
}
