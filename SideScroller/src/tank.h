#ifndef TANK_H
#define TANK_H
#include <iostream>
#include "gameState.h"
#include "play.h"
#include <math.h>
#include "raylib.h"

using namespace std;
namespace sideScroller {
#define ARRAYSIZE 5



	//extern Asteroide aArray[ARRAYSIZE];



	void InitTank(Vector2 a1, Vector2 a2, Vector2 a3, Vector2 a4, Vector2 a5);
	void UpdateTank();
	bool TankColisionRec(Rectangle r, bool bullet);
	void DrawTank();
	void DestroyTank(int i);
	bool GetDestroyedTank(int i);
	bool AllDestroyed();
};
#endif
