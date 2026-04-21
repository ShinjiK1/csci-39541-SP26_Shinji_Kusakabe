#pragma once

#include"pch.h"
#include"TonkatsuUtility.h"
#include"Shader.h"
#include"Picture.h"
#include"RendererImplementation.h"
#include"ThirdParty/OpenGL/RendererOpenGL.h"

namespace Tonkatsu
{
	class TONKATSU_API Renderer
	{
	public:
		static void Init();
		static std::unique_ptr<Renderer>& Get();

		void Draw(Picture& pic, int xCoord, int yCoord);
		void Draw(Picture& pic, int xCoord, int yCoord, Shader& shader);

		void ScreenClear();

	private:
		std::unique_ptr<RendererImplementation> mImplementation;

		Shader mDefaultShaders;

		Renderer();
		inline static std::unique_ptr<Renderer> mInstance;
	};
}