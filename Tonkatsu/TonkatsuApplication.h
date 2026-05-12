#pragma once

#include"pch.h"
#include"TonkatsuUtility.h"
#include"TonkatsuEvents.h"

constexpr int FPS{ 60 };

namespace Tonkatsu
{
	class TONKATSU_API TonkatsuApplication
	{
	public:
		TonkatsuApplication();
		virtual void Update();
		virtual void Initialize();
		virtual void Shutdown();
		void Run();

		void SetKeyCallback(std::function<void(const KeyEvent&)> newCallback);
		void SetWindowCloseCallback(std::function<void(const WindowCloseEvent&)> newCallback);

		virtual ~TonkatsuApplication();

	private:
		std::chrono::milliseconds mFrameDuration{ 1000 / FPS };
		std::chrono::steady_clock::time_point mNextFrameTime;

		bool mShouldContinue{ true };
		void DefaultWindowCloseCallback(const WindowCloseEvent&);
	};
}