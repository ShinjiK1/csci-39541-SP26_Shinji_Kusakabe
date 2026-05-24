#pragma once

#include"Tonkatsu.h"

class Ball;

class Paddle {
public:
	Paddle(bool isCpu);
	void MoveUp(int amount);
	void MoveDown(int amount);
	void HandleCPU(const Ball& target);
	int GetId() const;


	Tonkatsu::Unit sprite;
private:
	int id;
	bool isCPU;
};