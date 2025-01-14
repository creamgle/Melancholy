#pragma once
#include "Melancholy/Core.h"
#include "Melancholy/Core/Color.h"
#include "Melancholy/Renderer/GraphicsApi.h"
#include "Melancholy/Renderer/Texture2D.h"

namespace Melancholy::Renderer2D {

	MAPI bool Initialise();
	MAPI void Destroy();

	MAPI void Clear();

	MAPI void SetBackgroundColor(float r, float g, float b, float a);

	MAPI void DrawColoredRect(float x, float y, float w, float h, Color color);
	MAPI void DrawTexture(float x, float y, float w, float h, Ref<Texture2D> texture);

	MAPI GraphicsApi& GetGraphicsApi();
}
