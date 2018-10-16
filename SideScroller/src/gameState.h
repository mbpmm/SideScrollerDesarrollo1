#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "raylib.h"
#include "play.h"
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

	static void InitGame();
	void PlayGame();
	static void UpdateGame();
	static void DrawGame();
	
};
#endif
