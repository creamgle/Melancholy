#include "Melancholy/Core.h"
#include "Melancholy/Core/Application.h"
#include "Melancholy/Core/Math.h"
#include "Melancholy/Renderer/Renderer2D.h"

using namespace Melancholy;

class SandboxApp : public Application {
public:
    ~SandboxApp() override = default;

    bool Create() override 
    {
        MTRACE("Creating sandbox app...");

		Vector3 a = { 5, 0, 0 };
		Vector3 b = { 10, -10, 15 };

		Vector3 c = a + b;
		MDEBUG("{}", Vector3::Normalized(a).ToString());
		MDEBUG("Length: {}", Vector3::Length(a));

        return true;
    }

	void Draw() override
	{
		Renderer2D::SetBackgroundColor(0.0f, 0.0f, 1.0f, 1.0f);
		Renderer2D::Clear();
	}
};

int main() 
{
	ApplicationConfig config;
	config.WindowConfig.Width = 800;
	config.WindowConfig.Height = 450;
	config.WindowConfig.Title = "Sandbox [Melancholy]";
	
    Application* app = new SandboxApp();
    app->Run(config);
    delete app;
}
