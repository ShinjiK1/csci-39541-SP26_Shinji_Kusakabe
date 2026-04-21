#pragma once

#define START_TONKATSU_GAME(className) \
int main()\
{\
	className game;\
	game.Run();\
	return 0;\
}