#include"Hat.h"

#include<iostream>

class Game : public Hat::HatApplication
{
	virtual void Update() override
	{
		//HAT_LOG("Running nicely!");
	}
};

START_HAT_GAME(Game);