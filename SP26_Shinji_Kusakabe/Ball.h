#pragma once

#include"Tonkatsu.h"

class Paddle;

class Ball {
public:
	Ball();
	void InitializeMove();
	void Reset();
	int HandleMove();
	void CheckCollision(const Paddle& paddle);
	int GetXSpeed() const;
	int GetYSpeed() const;


	Tonkatsu::Unit sprite;
private:
	int xSpeed;
	int ySpeed;
	int lastCollidedId;
};