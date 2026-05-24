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
			else if (event.GetKeyCode() == Tonkatsu::Key::SPACE && event.GetAction() == Tonkatsu::KeyAction::PRESS && !inProgress) {
				inProgress = true;
				state = 1;
				ball.Reset();
				p1.Reset();
				p2.Reset();
				ball.InitializeMove();
			}
		});
		startScreen.LoadImage("Assets/Images/Start.png");
		loseScreen.LoadImage("Assets/Images/LoseScreen.png");
		winScreen.LoadImage("Assets/Images/WinScreen.png");
	}

	virtual void Update() override
	{
		/*
		if (Collide(unit, unit2)) {
			TONKATSU_LOG("Collision!");
		}
		*/
		if (inProgress) {
			p2.HandleCPU(ball);
			switch(ball.HandleMove()) {
				case 0:
					TONKATSU_LOG("Ongoing");
					break;
				case 1:
					TONKATSU_LOG("YOU LOSE");
					inProgress = false;
					state = 2;
					break;
				case 2:
					TONKATSU_LOG("YOU WIN");
					inProgress = false;
					state = 3;
					break;
			}
			ball.CheckCollision(p1);
			ball.CheckCollision(p2);
		}
		else {
			if (state == 0) {
				Tonkatsu::Renderer::Get()->Draw(startScreen, 0, 0);
			}
			if (state == 2) {
				Tonkatsu::Renderer::Get()->Draw(loseScreen, 0, 0);
			}
			if (state == 3) {
				Tonkatsu::Renderer::Get()->Draw(winScreen, 0, 0);
			}
		}

		Tonkatsu::Renderer::Get()->Draw(p1.sprite);
		Tonkatsu::Renderer::Get()->Draw(p2.sprite);
		Tonkatsu::Renderer::Get()->Draw(ball.sprite);
	}
private:
	Paddle p1{ false };
	Paddle p2{ true };
	Ball ball;
	Tonkatsu::Picture startScreen;
	Tonkatsu::Picture winScreen;
	Tonkatsu::Picture loseScreen;
	bool inProgress{ false };
	int state{ 0 }; //0 = before start, 1 = ongoing, 2 = player lost, 3 = player won
};

START_TONKATSU_GAME(Game);