#pragma once

#include"pch.h"
#include"HatUtility.h"
#include"Shader.h"
#include"Picture.h"
#include"RendererImplementation.h"
#include"ThirdParty/OpenGL/RendererOpenGL.h"

namespace Hat
{
	class HAT_API Renderer
	{
	public:
		static void Init();
		static std::unique_ptr<Renderer>& Get();

		void Draw(const Picture& pic, int xCoord, int yCoord);
		void Draw(const Picture& pic, int xCoord, int yCoord, const Shader& shader);

	private:
		std::unique_ptr<RendererImplementation> mImplementation;

		Shader mDefaultShaders;

		Renderer();
		inline static std::unique_ptr<Renderer> mInstance;
	};
}