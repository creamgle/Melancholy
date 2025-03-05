#pragma once
#include "Melancholy/Defines.h"
#include <string>

namespace Melancholy {

	struct WindowProps {
		int Width = 800;
		int Height = 450;
		std::string Title = "My Game [Melancholy]";
	};

	class Window {	
	public:
		virtual ~Window() = default;

		static Window* Create(const WindowProps& props = { });

		virtual bool Initialise() = 0;
		virtual void Shutdown() = 0;

		virtual void PollEvents() = 0;
		virtual bool ShouldClose() = 0;
	};

}