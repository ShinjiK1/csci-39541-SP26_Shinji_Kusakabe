#pragma once

#include"pch.h"
#include"HatTypes.h"

namespace Hat
{
	class PictureImplementation
	{
	public:
		virtual void LoadImage(const std::string& fileName) = 0;
		virtual Dimensions GetDimensions() const = 0;
		virtual void Bind() = 0;

		virtual ~PictureImplementation() {};
	};
}