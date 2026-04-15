#include"pch.h"

#include"Renderer.h"

namespace Hat
{
	void Renderer::Init()
	{
		if (!mInstance) {
			mInstance = std::unique_ptr<Renderer>{ new Renderer };
		}
	}

	std::unique_ptr<Renderer>& Renderer::Get()
	{
		return mInstance;
	}

	void Renderer::Draw(Picture& pic, int xCoord, int yCoord)
	{
		mImplementation->Draw(pic, xCoord, yCoord, mDefaultShaders);
	}

	void Renderer::Draw(Picture& pic, int xCoord, int yCoord, Shader& shader)
	{
		mImplementation->Draw(pic, xCoord, yCoord, shader);
	}

	void Renderer::ScreenClear()
	{
		mImplementation->ScreenClear();
	}

	Renderer::Renderer() {
#ifdef HAT_OPENGL
		mImplementation = std::unique_ptr<RendererImplementation>{ new RendererOpenGL };
		mDefaultShaders.LoadShader("../Hat/Assets/Shaders/defaultVertexShader.glsl", "../Hat/Assets/Shaders/defaultFragShader.glsl");
#else
		#only_OpenGL_is_supported
#endif
	}
}