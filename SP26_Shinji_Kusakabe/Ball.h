#pragma once

#include"Tonkatsu.h"

class Paddle;

class Ball {
public:
	Ball();
	void HandleMove();
	void OnCollideWall();
	void OnCollidePaddle(const Paddle& paddle);
	int GetXSpeed() const;
	int GetYSpeed() const;


	Tonkatsu::Unit sprite;
private:
	int xSpeed;
	int ySpeed;
};