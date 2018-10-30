#ifndef BOMB_H
#define BOMB_H
#include <iostream>
#include "raylib.h"
#include "gameState.h"

namespace sideScroller {

	void BombMovement(Rectangle ship);
	void SetShotBomb(bool sho);
	bool GetShotBomb();
	void DrawBomb();
	Rectangle GetRectBomb();
	void UpdateBomb(Rectangle ship);
};
#endif 


