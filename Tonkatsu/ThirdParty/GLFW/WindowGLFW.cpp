#include"pch.h"

#include"WindowGLFW.h"
#include"../../TonkatsuUtility.h"

namespace Tonkatsu
{
	void WindowGLFW::Create(Dimensions dimensions, const std::string windowName)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		mWindowPtr = glfwCreateWindow(dimensions.width, dimensions.height, windowName.c_str(), NULL, NULL);
		if (mWindowPtr == nullptr)
		{
			TONKATSU_ERROR("Failed to create GLFW window");
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(mWindowPtr);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			TONKATSU_ERROR("Could not initialize GLAD");
		}
	}

	Dimensions WindowGLFW::GetSize() const
	{
		int width{ 0 }, height{ 0 };

		glfwGetWindowSize(mWindowPtr,&width,&height);

		return { width,height };
	}

	void WindowGLFW::SwapBuffers()
	{
		glfwSwapBuffers(mWindowPtr);
	}
	
	void WindowGLFW::PollEvents()
	{
		glfwPollEvents();
	}
}