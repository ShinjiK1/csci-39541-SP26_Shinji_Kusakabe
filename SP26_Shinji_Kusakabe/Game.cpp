#include"Tonkatsu.h"

#include<iostream>

class Game : public Tonkatsu::TonkatsuApplication
{
	virtual void Update() override
	{
		//HAT_LOG("Running nicely!");
	}
};

START_TONKATSU_GAME(Game);