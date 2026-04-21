#pragma once

#include"Picture.h"
#include"Shader.h"

namespace Tonkatsu
{
	class RendererImplementation
	{
	public:
		virtual void Draw(Picture& pic, int xCoord, int yCoord, Shader& shader) = 0;
		virtual void ScreenClear() = 0;

		virtual ~RendererImplementation() {};
	};
}