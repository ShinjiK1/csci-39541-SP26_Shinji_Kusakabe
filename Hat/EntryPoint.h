#pragma once

#define START_HAT_GAME(className) \
int main()\
{\
	className game;\
	game.Run();\
	return 0;\
}