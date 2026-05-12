#include"pch.h"

#include"Window.h"
#include"ThirdParty/GLFW/WindowGLFW.h"

namespace Tonkatsu
{
	Window::Window()
	{
#ifdef TONKATSU_GLFW
		mImplementation = std::unique_ptr<WindowImplementation>{ new WindowGLFW };
#else
		#only_GLFW_is_supported
#endif
	}

	void Window::Init()
	{
		if (!mInstance) {
			mInstance = std::unique_ptr<Window>{ new Window };
		}
	}

	std::unique_ptr<Window>& Window::Get()
	{
		return mInstance;
	}

	void Window::Create(Dimensions dimensions, const std::string windowName)
	{
		mImplementation->Create(dimensions, windowName);
	}

	Dimensions Window::GetSize() const
	{
		return mImplementation->GetSize();
	}

	void Window::SwapBuffers()
	{
		mImplementation->SwapBuffers();
	}

	void Window::PollEvents()
	{
		mImplementation->PollEvents();
	}

	void Window::SetKeyCallback(std::function<void(const KeyEvent&)> newCallback)
	{
		mImplementation->SetKeyCallback(newCallback);
	}

	void Window::SetWindowCloseCallback(std::function<void(const WindowCloseEvent&)> newCallback)
	{
		mImplementation->SetWindowCloseCallback(newCallback);
	}
}