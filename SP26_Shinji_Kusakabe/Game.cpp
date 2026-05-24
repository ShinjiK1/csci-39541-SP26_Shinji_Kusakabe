#include"Tonkatsu.h"
#include"Paddle.h"
#include"Ball.h"

#include<iostream>

class Game : public Tonkatsu::TonkatsuApplication
{
	void Initialize() override {
		SetKeyCallback([this](const Tonkatsu::KeyEvent& event) {
			if (event.GetKeyCode() == Tonkatsu::Key::UP && (event.GetAction() == Tonkatsu::KeyAction::REPEAT || event.GetAction() == Tonkatsu::KeyAction::PRESS)) {
				p1.MoveUp(15);
			}
			else if (event.GetKeyCode() == Tonkatsu::Key::DOWN && (event.GetAction() == Tonkatsu::KeyAction::REPEAT || event.GetAction() == Tonkatsu::KeyAction::PRESS)) {
				p1.MoveDown(15);
			}
		});
	}

	virtual void Update() override
	{
		/*
		if (Collide(unit, unit2)) {
			TONKATSU_LOG("Collision!");
		}
		*/

		ball.HandleMove();

		Tonkatsu::Renderer::Get()->Draw(p1.sprite);
		Tonkatsu::Renderer::Get()->Draw(p2.sprite);
		Tonkatsu::Renderer::Get()->Draw(ball.sprite);
	}
private:
	Paddle p1{ false };
	Paddle p2{ true };
	Ball ball;
};

START_TONKATSU_GAME(Game);