#pragma once

#include"pch.h"
#include"WindowImplementation.h"
#include"TonkatsuUtility.h"
#include"TonkatsuTypes.h"
#include"TonkatsuEvents.h"

namespace Tonkatsu
{
	class TONKATSU_API Window
	{
	public:

		static void Init();
		static std::unique_ptr<Window>& Get();

		void Create(Dimensions dimensions, const std::string windowName);
		Dimensions GetSize() const;

		void SwapBuffers();
		void PollEvents();

		void SetKeyCallback(std::function<void(const KeyEvent&)> newCallback);
		void SetWindowCloseCallback(std::function<void(const WindowCloseEvent&)> newCallback);

	private:
		Window();
		inline static std::unique_ptr<Window> mInstance{ nullptr };

		std::unique_ptr<WindowImplementation> mImplementation{ nullptr };
	};
}