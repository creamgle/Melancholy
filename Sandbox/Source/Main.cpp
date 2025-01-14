#include "Melancholy/Core.h"
#include "Melancholy/Core/Application.h"
#include "Melancholy/Core/Math.h"
#include "Melancholy/Renderer/Mesh.h"
#include "Melancholy/Renderer/Renderer2D.h"
#include "Melancholy/Renderer/Shader.h"
#include "Melancholy/Renderer/Texture2D.h"
#include <string>
#include <vector>

using namespace Melancholy;

class SandboxApp : public Application {
public:
    ~SandboxApp() override = default;

    bool Create() override 
    {
        MTRACE("Creating sandbox app...");

		mTexture = Texture2D::Load("./Assets/Image.png");

        return true;
    }

	void Draw() override
	{
		time += 0.01f;
		float y = Math::Sin(time) * 125;
		y += 175;

		float x = Math::Cos(time) * 100;
		x += 350; 

		Renderer2D::SetBackgroundColor(0.2f, 0.2f, 0.2f, 1.0f);
		Renderer2D::Clear();

		Renderer2D::DrawColoredRect(x, y, 100, 100, { 1, 0, 1, 1 });	
		Renderer2D::DrawTexture(100, 100, 150, 150, mTexture);		

		// Renderer2D::SetBackgroundColor(0.1f, 0.1f, 0.1f, 1);
		// Renderer2D::Clear();

		// Renderer2D::DrawColoredRect(100, 100, 50, 50, { 1.0f, 0.0f, 0.0f, 1.0f });
	}

private:
	float time;
	Ref<Texture2D> mTexture;
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
