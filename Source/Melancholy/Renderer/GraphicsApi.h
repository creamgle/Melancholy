#pragma once

namespace Melancholy {

	class GraphicsApi {
	public:
		virtual ~GraphicsApi() = default;

		static GraphicsApi* Create();

		virtual void Clear() = 0;

		virtual void SetClearColor(float r, float g, float b, float a) = 0;
	};

}
