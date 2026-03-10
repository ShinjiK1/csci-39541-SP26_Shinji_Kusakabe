#pragma once

#include"GLFW/glfw3.h"

#include "../../WindowImplementation.h"
#include"../../HatTypes.h"

namespace Hat
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