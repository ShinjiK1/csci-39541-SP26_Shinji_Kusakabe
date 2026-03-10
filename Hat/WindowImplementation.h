#pragma once

#include"pch.h"
#include"HatTypes.h"

namespace Hat
{
	class WindowImplementation
	{
	public:
		virtual void Create(Dimensions dimensions, const std::string windowName) = 0;
		virtual Dimensions GetSize() const = 0;

		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;

		virtual ~WindowImplementation() {};
	};
}