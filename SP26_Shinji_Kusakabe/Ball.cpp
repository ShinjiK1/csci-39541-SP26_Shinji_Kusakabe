#include"Ball.h"
#include"Paddle.h"
#include"Globals.h"
#include<cmath>
#include<random>

std::random_device rd;
std::mt19937 gen(rd());

std::uniform_int_distribution<> xSpeeds(12, 18); //Possible xSpeeds. 
std::uniform_int_distribution<> ySpeeds(25, 35); //Possible ySpeeds. 
std::uniform_int_distribution<> fiftyFifty(0, 1); //For random gen

Ball::Ball(): sprite("Assets/Images/BallSprite.png",480,380), lastCollidedId(-1), ySpeed(0), xSpeed(0)
{
	InitializeMove();
}

void Ball::InitializeMove()
{
	ySpeed = ySpeeds(gen);
	if (fiftyFifty(gen) == 1) {
		ySpeed *= -1;
	}

	xSpeed = xSpeeds(gen);
	if (fiftyFifty(gen) == 1) {
		TONKATSU_LOG("BALL SHOULD BE GOING LEFT");
		xSpeed *= -1;
	}
}

void Ball::Reset()
{
	sprite.SetCoordinates(480, 380);
	lastCollidedId = -1;
}

int Ball::HandleMove()
{
	sprite.IncrementXPosition(xSpeed);
	sprite.IncrementYPosition(ySpeed);

	//Move back within screen border if goes past
	if (sprite.GetYCoordinate() > screenY - sprite.GetDimensions().width) {
		sprite.SetCoordinates(sprite.GetXCoordinate(), screenY - sprite.GetDimensions().width);
	}
	if (sprite.GetYCoordinate() < 0) {
		sprite.SetCoordinates(sprite.GetXCoordinate(), 0);
	}

	//If hit border from top/bottom change direction
	if (sprite.GetYCoordinate() <= 0 && ySpeed < 0) {
		ySpeed *= -1;
	}
	if (sprite.GetYCoordinate() >= screenY - sprite.GetDimensions().height && ySpeed > 0) {
		ySpeed *= -1;
	}

	if (sprite.GetXCoordinate() <= -1 * sprite.GetDimensions().width) {
		return 1;
	}
	else if (sprite.GetXCoordinate() >= screenX) {
		return 2;
	}
	return 0;
}

void Ball::CheckCollision(const Paddle& paddle)
{
	if (paddle.GetId() == lastCollidedId) {
		return;
	}
	if (Collide(sprite, paddle.sprite)) {
		int xSpeedSign = (xSpeed > 0) ? 1 : -1;
		xSpeed = xSpeeds(gen) * xSpeedSign * -1; //Times -1 because we want to horizontally flip/bounce the ball back when it hits a paddle

		int ySpeedSign = (ySpeed > 0) ? 1 : -1;
		ySpeed = ySpeeds(gen) * ySpeedSign; //No times -1 because we don't want to vertically change the ball's speed here.

		lastCollidedId = paddle.GetId();
	}
}

int Ball::GetXSpeed() const
{
	return xSpeed;
}

int Ball::GetYSpeed() const
{
	return ySpeed;
}
