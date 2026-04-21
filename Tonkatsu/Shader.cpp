#include"pch.h"

#include"Shader.h"
#include"ThirdParty/OpenGL/ShaderOpenGL.h"

namespace Tonkatsu
{
	Shader::Shader()
	{
#ifdef TONKATSU_OPENGL
		mImplementation = std::unique_ptr<ShaderImplementation>{ new ShaderOpenGL };
#else
		#only_openGL_is_supported
#endif
	}

	Shader::Shader(const std::string& vertexFileName, const std::string& fragmentFileName)
	{
#ifdef TONKATSU_OPENGL
		mImplementation = std::unique_ptr<ShaderImplementation>{ new ShaderOpenGL(vertexFileName, fragmentFileName)};
#else
		#only_openGL_is_supported
#endif
	}

	void Shader::LoadShader(const std::string& vertexFileName, const std::string& fragmentFileName)
	{
		mImplementation->LoadShader(vertexFileName, fragmentFileName);
	}

	void Shader::SupplyIntUniform(const std::string& uniformName, const std::vector<int>& vals)
	{
		mImplementation->SupplyIntUniform(uniformName, vals);
	}
	
	void Shader::Bind() {
		mImplementation->Bind();
	}
}