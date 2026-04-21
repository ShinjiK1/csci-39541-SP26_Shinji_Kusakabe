#include"pch.h"

#include"Picture.h"
#include"ThirdParty/OpenGL/PictureOpenGL.h"

namespace Tonkatsu
{
	Picture::Picture()
	{
#ifdef TONKATSU_OPENGL
		mImplementation = std::unique_ptr<PictureImplementation>{ new PictureOpenGL };
#else
		#only_opengl_is_supported
#endif
	}

	Picture::Picture(const std::string& fileName)
	{
#ifdef TONKATSU_OPENGL
		mImplementation = std::unique_ptr<PictureImplementation>{ new PictureOpenGL(fileName) };
#else
		#only_opengl_is_supported
#endif
	}

	void Picture::LoadImage(const std::string& fileName)
	{
		mImplementation->LoadImage(fileName);
	}

	Dimensions Picture::GetDimensions() const
	{
		return mImplementation->GetDimensions();
	}

	void Picture::Bind()
	{
		mImplementation->Bind();
	}
}