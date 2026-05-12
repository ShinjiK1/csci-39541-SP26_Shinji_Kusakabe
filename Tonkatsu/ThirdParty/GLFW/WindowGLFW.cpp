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

		glfwSetWindowUserPointer(mWindowPtr, &mCallback);

		glfwSetKeyCallback(mWindowPtr, [](GLFWwindow* winPtr, int key, int scancode, int action, int mods) {
			KeyEvent event{ (Key)key, KeyAction::UNDEFINED };

			if (action == GLFW_PRESS) {
				event.SetAction(KeyAction::PRESS);
			}
			else if (action == GLFW_REPEAT) {
				event.SetAction(KeyAction::REPEAT);
			}
			else if (action == GLFW_RELEASE) {
				event.SetAction(KeyAction::RELEASE);
			}

			Callbacks* userPtr{ (Callbacks*)glfwGetWindowUserPointer(winPtr) };

			userPtr->KeyCallback(event); // calling mKeyCallback(event)
		});

		glfwSetWindowCloseCallback(mWindowPtr, [](GLFWwindow* winPtr) {
			WindowCloseEvent event;
			
			Callbacks* userPtr{ (Callbacks*)glfwGetWindowUserPointer(winPtr) };

			userPtr->WindowCloseCallback(event); // calling mWindowCloseCallback(event)
		});
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

	void WindowGLFW::SetKeyCallback(std::function<void(const KeyEvent&)> newCallback)
	{
		mCallback.KeyCallback = newCallback;
	}

	void WindowGLFW::SetWindowCloseCallback(std::function<void(const WindowCloseEvent&)> newCallback)
	{
		mCallback.WindowCloseCallback = newCallback;
	}
}