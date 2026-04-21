#include"pch.h"
#include"HatApplication.h"
#include"Window.h"

#include"glad/glad.h"

#include"stbi.h"

#include"Picture.h"
#include"Shader.h"
#include"Renderer.h"

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
		Window::Get()->Create({1000,800}, "FallGame");

		Renderer::Init();

		Initialize();

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		
		Picture pic{ "../Hat/Assets/Images/Character.png" };
		int pos = 2;

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (true) {
			Renderer::Get()->ScreenClear();

			Update();

			Renderer::Get()->Draw(pic, pos, 2);
			pos++;

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			Window::Get()->SwapBuffers();
			Window::Get()->PollEvents();
		}

		Shutdown();
	}

	HatApplication::~HatApplication()
	{

	}
}