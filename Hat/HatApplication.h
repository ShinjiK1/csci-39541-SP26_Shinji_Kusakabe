#pragma once

#include"HatUtility.h"

constexpr int FPS{ 60 };

namespace Hat
{
	class HAT_API HatApplication
	{
	public:
		virtual void Update();
		virtual void Initialize();
		virtual void Shutdown();
		void Run();

		virtual ~HatApplication();

	private:
		std::chrono::milliseconds mFrameDuration{ 1000 / FPS };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}