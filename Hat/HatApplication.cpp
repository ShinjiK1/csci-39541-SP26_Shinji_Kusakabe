#include"pch.h"
#include"HatApplication.h"

namespace Hat
{
	void HatApplication::Update()
	{

	}

	void HatApplication::Initialize()
	{

	}

	void HatApplication::Shutdown()
	{

	}

	void HatApplication::Run()
	{
		Initialize();

		while (true) {
			Update();
		}

		Shutdown();
	}

	HatApplication::~HatApplication()
	{

	}
}