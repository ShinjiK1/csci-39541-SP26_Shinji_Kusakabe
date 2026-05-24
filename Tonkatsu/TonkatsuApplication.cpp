#include"pch.h"
#include"TonkatsuApplication.h"
#include"Window.h"

#include"glad/glad.h"
#include"GLFW/glfw3.h"

#include"stbi.h"

#include"Picture.h"
#include"Shader.h"
#include"Renderer.h"
#include"KeyCodes.h"
#include"Unit.h"

namespace Tonkatsu
{
	TonkatsuApplication::TonkatsuApplication() {
		Window::Init();
		Window::Get()->Create({1000,800}, "SpringGame");

		SetWindowCloseCallback([this](const WindowCloseEvent& event) {DefaultWindowCloseCallback(event); });

		Renderer::Init();
	}

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
		Initialize();

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (mShouldContinue) {
			Renderer::Get()->ScreenClear();

			Update();

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			Window::Get()->SwapBuffers();
			Window::Get()->PollEvents();
		}

		Shutdown();
	}

	void TonkatsuApplication::SetKeyCallback(std::function<void(const KeyEvent&)> newCallback)
	{
		Window::Get()->SetKeyCallback(newCallback);
	}

	void Tonkatsu::TonkatsuApplication::SetWindowCloseCallback(std::function<void(const WindowCloseEvent&)> newCallback)
	{
		Window::Get()->SetWindowCloseCallback(newCallback);
	}

	TonkatsuApplication::~TonkatsuApplication()
	{

	}

	void Tonkatsu::TonkatsuApplication::DefaultWindowCloseCallback(const WindowCloseEvent&)
	{
		mShouldContinue = false;
	}
}