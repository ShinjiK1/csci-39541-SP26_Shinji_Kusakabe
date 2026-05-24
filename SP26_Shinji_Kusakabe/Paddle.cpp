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

void Paddle::MoveUp(int amount)
{
	if (sprite.GetYCoordinate() + amount > screenY - sprite.GetDimensions().width) {
		sprite.IncrementYPosition(screenY - sprite.GetDimensions().width - sprite.GetYCoordinate());
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

void Paddle::HandleCPU(const Ball& target)
{

}