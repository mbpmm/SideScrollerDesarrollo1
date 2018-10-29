#ifndef BULLET_H
#define BULLET_H
#include <iostream>
#include "raylib.h"
#include "gameState.h"
namespace sideScroller {
	
	const int BULLETSPEED = 1000;
	void BulletMovement(Rectangle ship);
	void SetShot(bool sho);
	bool GetShot();
	void DrawBullet();
	Rectangle GetRect();
	void UpdateBullet(Rectangle ship);
};
#endif 

