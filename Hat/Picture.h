#pragma once

#include"pch.h"

#include"HatUtility.h"
#include"HatTypes.h"
#include"PictureImplementation.h"

namespace Hat
{
	class HAT_API Picture
	{
	public:
		Picture();
		Picture(const std::string& fileName);
		void LoadImage(const std::string& fileName);
		Dimensions GetDimensions() const;

	private:
		std::unique_ptr<PictureImplementation> mImplementation;
		void Bind();

		friend class RendererOpenGL;
	};
}