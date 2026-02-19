#pragma once

#include"HatUtility.h"

namespace Hat
{
	class HAT_API HatApplication
	{
	public:
		virtual void Update();
		virtual void Initialize();
		virtual void Shutdown();
		void Run();

		virtual ~HatApplication();

	private:

	};
}