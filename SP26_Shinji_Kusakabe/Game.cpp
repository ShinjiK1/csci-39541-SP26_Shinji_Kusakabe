#include"Tonkatsu.h"

#include<iostream>

class Game : public Tonkatsu::TonkatsuApplication
{
	void Initialize() override {
		SetKeyCallback([this](const Tonkatsu::KeyEvent& event) {
			if (event.GetKeyCode() == Tonkatsu::Key::RIGHT && event.GetAction() == Tonkatsu::KeyAction::PRESS) {
				unit.IncrementXPosition(5);
			}
			else if (event.GetKeyCode() == Tonkatsu::Key::LEFT && event.GetAction() == Tonkatsu::KeyAction::PRESS) {
				unit.IncrementXPosition(-5);
			}
		});
	}

	virtual void Update() override
	{
		//HAT_LOG("Running nicely!");
		if (Collide(unit, unit2)) {
			TONKATSU_LOG("Collision!");
		}

		Tonkatsu::Renderer::Get()->Draw(unit);
		Tonkatsu::Renderer::Get()->Draw(unit2);
	}
private:
	Tonkatsu::Unit unit{ "../Tonkatsu/Assets/Images/Character.png", 10, 10 };
	Tonkatsu::Unit unit2{ "../Tonkatsu/Assets/Images/Character.png", 300, 10 };
};

START_TONKATSU_GAME(Game);