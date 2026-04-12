#pragma once

#include"pch.h"
#include"HatUtility.h"
#include"ShaderImplementation.h"

namespace Hat
{
	class HAT_API Shader
	{
	public:
		Shader();
		Shader(const std::string& vertexFileName, const std::string& fragmentFileName);
		void LoadShader(const std::string& vertexFileName, const std::string& fragmentFileName);
		void SupplyIntUniform(const std::string& uniformName, const std::vector<int>& vals);

	private:
		std::unique_ptr<ShaderImplementation> mImplementation;
		void Bind();
	};
}