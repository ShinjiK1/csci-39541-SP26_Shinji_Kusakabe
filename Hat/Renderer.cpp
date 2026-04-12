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

	void Renderer::Draw(const Picture& pic, int xCoord, int yCoord)
	{
		mImplementation->Draw(pic, xCoord, yCoord);
	}

	void Renderer::Draw(const Picture& pic, int xCoord, int yCoord, const Shader& shader)
	{
		mImplementation->Draw(pic, xCoord, yCoord, shader);
	}

	Renderer::Renderer() {
#ifdef HAT_OPENGL
		mImplementation = std::unique_ptr<RendererImplementation>{ new RendererOpenGL };
#else
		#only_OpenGL_is_supported
#endif
	}
}