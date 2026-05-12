#pragma once

#include"pch.h"
#include"TonkatsuTypes.h"
#include"TonkatsuEvents.h"

namespace Tonkatsu
{
	class WindowImplementation
	{
	public:
		virtual void Create(Dimensions dimensions, const std::string windowName) = 0;
		virtual Dimensions GetSize() const = 0;

		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;

		virtual void SetKeyCallback(std::function<void(const KeyEvent& newCallback)>) = 0;
		virtual void SetWindowCloseCallback(std::function<void(const WindowCloseEvent& newCallback)>) = 0;

		virtual ~WindowImplementation() {};
	};
}