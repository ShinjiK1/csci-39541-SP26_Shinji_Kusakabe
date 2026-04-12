#pragma once

#include"RendererImplementation.h"

namespace Hat
{
	class RendererOpenGL : public RendererImplementation
	{
	public:
		virtual void Draw(const Picture& pic, int xCoord, int yCoord) override;
		virtual void Draw(const Picture& pic, int xCoord, int yCoord, const Shader& shader) override;

	private:

	};
}