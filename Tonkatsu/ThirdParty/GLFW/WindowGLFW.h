#pragma once

#define GLFW_INCLUDE_NONE
#include"GLFW/glfw3.h"
#include"glad/glad.h"

#include "../../WindowImplementation.h"
#include"../../TonkatsuTypes.h"

namespace Tonkatsu
{
	class WindowGLFW : public WindowImplementation
	{
	public:
		virtual void Create(Dimensions dimensions, const std::string windowName) override;
		virtual Dimensions GetSize() const override;

		virtual void SwapBuffers() override;
		virtual void PollEvents() override;
	private:
		GLFWwindow* mWindowPtr{ nullptr };
	};
}