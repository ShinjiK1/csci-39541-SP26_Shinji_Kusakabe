#include"pch.h"
#include"HatApplication.h"
#include"Window.h"

namespace Hat
{
	void HatApplication::Update()
	{

	}

	void HatApplication::Initialize()
	{

	}

	void HatApplication::Shutdown()
	{

	}

	void HatApplication::Run()
	{
		Window::Init();
		Window::Get()->Create({600,400}, "FallGame");

		Initialize();

		while (true) {
			Update();

			Window::Get()->SwapBuffers();
			Window::Get()->PollEvents();
		}

		Shutdown();
	}

	HatApplication::~HatApplication()
	{

	}
}