#pragma once

#include"pch.h"
#include"TonkatsuUtility.h"
#include"ShaderImplementation.h"

namespace Tonkatsu
{
	class TONKATSU_API Shader
	{
	public:
		Shader();
		Shader(const std::string& vertexFileName, const std::string& fragmentFileName);

		Shader(const Shader&) = delete;
		Shader& operator=(const Shader&) = delete;
		Shader(Shader&& other);
		Shader& operator=(Shader&& other);

		void LoadShader(const std::string& vertexFileName, const std::string& fragmentFileName);
		void SupplyIntUniform(const std::string& uniformName, const std::vector<int>& vals);

	private:
		std::unique_ptr<ShaderImplementation> mImplementation;
		void Bind();

		friend class RendererOpenGL;
	};
}