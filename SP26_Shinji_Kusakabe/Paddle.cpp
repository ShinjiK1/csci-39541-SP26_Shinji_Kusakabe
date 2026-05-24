#include"Paddle.h"
#include"Ball.h"
#include"Tonkatsu.h"
#include"Globals.h"

Paddle::Paddle(bool isCpu): isCPU(isCpu), sprite("Assets/Images/PaddleSprite.png")
{
	if (!isCpu) { // Player Position
		id = 0;
		sprite.SetCoordinates(110, 260);
	}
	else { // CPU/opponent position
		id = 1;
		sprite.SetCoordinates(screenX - 110 - sprite.GetDimensions().width, 260);
	}
}

void Paddle::Reset()
{
	if (!isCPU) {
		sprite.SetCoordinates(110, 260);
	}
	else {
		sprite.SetCoordinates(screenX - 110 - sprite.GetDimensions().width, 260);
	}
}

void Paddle::MoveUp(int amount)
{
	if (sprite.GetYCoordinate() + amount > screenY - sprite.GetDimensions().height) {
		sprite.IncrementYPosition(screenY - sprite.GetDimensions().height - sprite.GetYCoordinate());
	}
	else {
		sprite.IncrementYPosition(amount);
	}
}

void Paddle::MoveDown(int amount)
{
	if (sprite.GetYCoordinate() < amount) {
		sprite.IncrementYPosition(-1 * sprite.GetYCoordinate());
	}
	else {
		sprite.IncrementYPosition(-1 * amount);
	}
}

//Goal for cpu is to try to keep the center of the paddle aligned with the center of the ball
//This allows it to hit back the ball fairly well, but ensure that it will eventually lose if the
//Player keeps hitting the ball back as, the ball will change speeds and is faster than the max paddle
//Speed so you would have to preemptively move to where the ball is going to be in order to always hit it back, which the CPU doesn't do.
void Paddle::HandleCPU(const Ball& target)
{
	if (target.GetYSpeed() > 0 && target.sprite.GetYCoordinate() + target.sprite.GetDimensions().height / 2 > sprite.GetYCoordinate() + sprite.GetDimensions().height / 2) {
		MoveUp(15);
	}
	else if (target.GetYSpeed() < 0 && target.sprite.GetYCoordinate() + target.sprite.GetDimensions().height / 2 < sprite.GetYCoordinate() + sprite.GetDimensions().height / 2) {
		MoveDown(15);
	}
}

int Paddle::GetId() const
{
	return id;
}
