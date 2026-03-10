#pragma once

#include"HatUtility.h"

namespace Hat
{
	struct HAT_API Dimensions
	{
		unsigned width{ 0 };
		unsigned height{ 0 };

		Dimensions();
		Dimensions(int newWidth, int newHeight) : width(newWidth), height(newHeight) {};
	};
}