#pragma once

#include"Picture.h"
#include"Shader.h"

namespace Hat
{
	class RendererImplementation
	{
	public:
		virtual void Draw(const Picture& pic, int xCoord, int yCoord) = 0;
		virtual void Draw(const Picture& pic, int xCoord, int yCoord, const Shader& shader) = 0;

		virtual ~RendererImplementation() {};
	};
}