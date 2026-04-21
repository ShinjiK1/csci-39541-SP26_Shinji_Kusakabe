#pragma once

#include"pch.h"
#include"TonkatsuTypes.h"

namespace Tonkatsu
{
	class ShaderImplementation
	{
	public:
		virtual void LoadShader(const std::string& vertexFileName, const std::string& fragmentFileName) = 0;
		virtual void SupplyIntUniform(const std::string& uniformName, const std::vector<int>& vals) = 0;
		virtual void Bind() = 0;

		virtual ~ShaderImplementation() {};
	};
}