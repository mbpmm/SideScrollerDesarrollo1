#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "raylib.h"
#include "play.h"
#include "start.h"
#include "credit.h"
#include "ship.h"
#include "asteroid.h"
#include <iostream>
using namespace std;
namespace sideScroller
{
#define WHITE  CLITERAL{ 255, 255, 255, 255 }
	extern int screenWidth;
	extern int screenHeight;
	extern int score;
	extern int gameState;
	enum PlayState
	{
		Start,
		Play,
		GameOver,
		Credit,
		End
	};
	struct Asteroide {
		float x;
		float y;
		bool destroyed;
		float aRotation;
		float rotation;
		float aSpeed;
		Rectangle astRectangle;

	};
	static void InitGame();
	void PlayGame();
	static void UpdateGame();
	static void DrawGame();
	
};
#endif
