#pragma once

#include"pch.h"

#include"TonkatsuUtility.h"
#include"TonkatsuTypes.h"
#include"PictureImplementation.h"

namespace Tonkatsu
{
	class TONKATSU_API Picture
	{
	public:
		Picture();
		Picture(const std::string& fileName);

		Picture(const Picture&) = delete;
		Picture& operator=(const Picture&) = delete;

		Picture(Picture&& other);
		Picture& operator=(Picture&& other);

		void LoadImage(const std::string& fileName);
		Dimensions GetDimensions() const;

	private:
		std::unique_ptr<PictureImplementation> mImplementation;
		void Bind();

		friend class RendererOpenGL;
	};
}