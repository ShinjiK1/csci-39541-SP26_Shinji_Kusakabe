#pragma once

#include"HatUtility.h"

namespace Hat
{
	struct HAT_API Dimensions
	{
		int width{ 0 };
		int height{ 0 };

		Dimensions() {};
		Dimensions(int newWidth, int newHeight) : width(newWidth), height(newHeight) {};
	};
}