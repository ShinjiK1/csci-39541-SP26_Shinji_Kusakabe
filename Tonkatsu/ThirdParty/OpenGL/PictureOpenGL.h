#pragma once

#include"../../pch.h"
#include"../../PictureImplementation.h"
#include"../../TonkatsuTypes.h"

namespace Tonkatsu
{
	class PictureOpenGL : public PictureImplementation
	{
	public:
		PictureOpenGL();
		PictureOpenGL(const std::string& fileName);

		virtual void LoadImage(const std::string& fileName) override;
		virtual Dimensions GetDimensions() const override;
		virtual void Bind() override;

		virtual ~PictureOpenGL();

	private:
		unsigned int mTexture{ 0 };
		Dimensions mDimensions;
	};
}