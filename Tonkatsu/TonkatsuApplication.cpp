#include"pch.h"
#include"TonkatsuApplication.h"
#include"Window.h"

#include"glad/glad.h"

#include"stbi.h"

#include"Picture.h"
#include"Shader.h"
#include"Renderer.h"

namespace Tonkatsu
{
	void TonkatsuApplication::Update()
	{

	}

	void TonkatsuApplication::Initialize()
	{

	}

	void TonkatsuApplication::Shutdown()
	{

	}

	void TonkatsuApplication::Run()
	{
		Window::Init();
		Window::Get()->Create({1000,800}, "FallGame");

		Renderer::Init();

		Initialize();

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		
		Picture pic{ "../Tonkatsu/Assets/Images/Character.png" };
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

	TonkatsuApplication::~TonkatsuApplication()
	{

	}
}