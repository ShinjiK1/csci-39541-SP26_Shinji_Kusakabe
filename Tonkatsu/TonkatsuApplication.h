#pragma once

#include"TonkatsuUtility.h"

constexpr int FPS{ 60 };

namespace Tonkatsu
{
	class TONKATSU_API TonkatsuApplication
	{
	public:
		virtual void Update();
		virtual void Initialize();
		virtual void Shutdown();
		void Run();

		virtual ~TonkatsuApplication();

	private:
		std::chrono::milliseconds mFrameDuration{ 1000 / FPS };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}