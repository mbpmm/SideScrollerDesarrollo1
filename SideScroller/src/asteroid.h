#ifndef ASTEROID_H
#define ASTEROID_H
#include <iostream>
#include "gameState.h"
#include "play.h"
#include <math.h>
#include "raylib.h"

using namespace std;
namespace sideScroller {
#define ARRAYSIZE 5
	


	//extern Asteroide aArray[ARRAYSIZE];


	
	void InitAsteroid(Vector2 a1, Vector2 a2, Vector2 a3, Vector2 a4, Vector2 a5);
	void UpdateAsteroid();
	bool AsteroidColisionRec(Rectangle r);
	void DrawAsteroid();
	void DestroyAsteroid(int i);
	bool GetDestroyed(int i);
	bool AllDestroyed();
};
#endif