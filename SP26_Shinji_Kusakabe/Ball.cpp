#include"Ball.h"
#include"Paddle.h"
#include"Globals.h"
#include<cmath>
#include<random>

std::random_device rd;
std::mt19937 gen(rd());

std::uniform_int_distribution<> xSpeeds(20, 30); //Possible xSpeeds. 
std::uniform_int_distribution<> fiftyFifty(0, 1); //For random gen

Ball::Ball(): sprite("Assets/Images/Ballsprite.png",480,380)
{
	if (fiftyFifty(gen) == 0) {
		ySpeed = 25;
	}
	else {
		ySpeed = -25;
	}
	xSpeed = xSpeeds(gen);
}

void Ball::HandleMove()
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
}

void Ball::OnCollideWall()
{

}

void Ball::OnCollidePaddle(const Paddle& paddle)
{

}

int Ball::GetXSpeed() const
{
	return xSpeed;
}

int Ball::GetYSpeed() const
{
	return ySpeed;
}
