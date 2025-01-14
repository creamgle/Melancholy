#include "Renderer2D.h"
#include "Melancholy/Core/Math.h"
#include "Melancholy/Renderer/GraphicsApi.h"
#include "Melancholy/Renderer/Mesh.h"
#include "Melancholy/Renderer/Shader.h"

namespace Melancholy::Renderer2D {

	static Scope<GraphicsApi> _GraphicsApi;

	static Ref<Mesh> _QuadMesh;
	static Ref<Shader> _Shader;

	static Matrix4 _Projection;

	static void CreateQuadMesh()
	{
		std::vector<Vertex> vertices = {
			{ { 0, 0, 0 }, { 0, 0, -1 }, { 0, 0 } },
			{ { 0, 1, 0 }, { 0, 0, -1 }, { 0, 1 } },
			{ { 1, 0, 0 }, { 0, 0, -1 }, { 1, 0 } },
			{ { 1, 1, 0 }, { 0, 0, -1 }, { 1, 1 } }
		};

		std::vector<uint32> triangles = { 
			0, 1, 2,
			2, 1, 3
		};

		_QuadMesh = Mesh::Create(vertices, triangles);
	}

	static void CreateShader()
	{

		const std::string& vertex = R"(
			#version 330

			layout(location=0) in vec3 aPosition;
			layout(location=2) in vec2 aTexCoord;
			
			out vec2 vTexCoord;

			uniform mat4 uModel;
			uniform mat4 uProjection;

			void main()
			{
				gl_Position = uProjection * uModel * vec4(aPosition, 1.0);
				vTexCoord = aTexCoord;
			}
		)";

		const std::string& fragment = R"(
			#version 330

			layout(location=0) out vec4 oFragColor;

			in vec2 vTexCoord;

			uniform sampler2D uMainTex;
			uniform vec4 uColor;

			void main()
			{
				vec4 color = uColor;
				if (color.a < 0)
					color = texture(uMainTex, vTexCoord);

				oFragColor = color;
			}
		)";

		_Shader = Shader::Create(vertex, fragment);
	}

	bool Initialise()
	{
		_GraphicsApi = GraphicsApi::Create();
		if (!_GraphicsApi)
		{
			MFATAL("Failed to get graphics api!");
			return false;
		}

		CreateQuadMesh();
		CreateShader();

		// TODO: Validate that resources were created correctly

		return true;
	}

	void Destroy()
	{
	}

	void Clear()
	{
		_GraphicsApi->Clear();

		// TODO: Get windows actual dimensions
		_Projection = Matrix4::Ortho(0, 800, 0, 450, 0, 100);
	}

	void SetBackgroundColor(float r, float g, float b, float a)
	{
		_GraphicsApi->SetClearColor(r, g, b, a);
	}

	void DrawColoredRect(float x, float y, float w, float h, Color color)
	{
		Matrix4 model = Matrix4::Translate(x, y, 0) * Matrix4::Scale(w, h, 1);

		_Shader->Bind();
		_Shader->SetUniformFloat4("uColor", color.r, color.g, color.b, color.a);
		_Shader->SetUniformMatrix4("uModel", model);
		_Shader->SetUniformMatrix4("uProjection", _Projection);
		_QuadMesh->Draw();
	}

	void DrawTexture(float x, float y, float w, float h, Ref<Texture2D> texture)
	{
		Matrix4 model = Matrix4::Translate(x, y, 0) * Matrix4::Scale(w, h, 1);

		_Shader->Bind();
		_Shader->SetUniformFloat4("uColor", 0, 0, 0, -1 );
		_Shader->SetUniformMatrix4("uModel", model);
		_Shader->SetUniformMatrix4("uProjection", _Projection);
		texture->Bind(0);
		_QuadMesh->Draw();
	}

	GraphicsApi& GetGraphicsApi()
	{
		return *_GraphicsApi;
	}

}
