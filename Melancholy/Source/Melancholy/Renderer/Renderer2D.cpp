#include "Renderer2D.h"
#include "Melancholy/Renderer/GraphicsApi.h"

namespace Melancholy::Renderer2D {

	static Scope<GraphicsApi> _GraphicsApi;

	bool Initialise()
	{
		_GraphicsApi = GraphicsApi::Create();
		if (!_GraphicsApi)
		{
			MFATAL("Failed to get graphics api!");
			return false;
		}
		return true;
	}

	void Destroy()
	{
	}

	void Clear()
	{
		_GraphicsApi->Clear();
	}

	void SetBackgroundColor(float r, float g, float b, float a)
	{
		_GraphicsApi->SetClearColor(r, g, b, a);
	}

}
