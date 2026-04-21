#pragma once

#include"TonkatsuUtility.h"

namespace Tonkatsu
{
	struct TONKATSU_API Dimensions
	{
		int width{ 0 };
		int height{ 0 };

		Dimensions() {};
		Dimensions(int newWidth, int newHeight) : width(newWidth), height(newHeight) {};
	};
}