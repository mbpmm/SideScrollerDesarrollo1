#include "bullet.h"
namespace sideScroller {
	
	static bool Shot = false;
	static Rectangle Bullet = { -100, -100, SQUARE / 4, SQUARE / 4 };
	void BulletMovement(Rectangle ship) {
		if (Shot) {
			//Bullet.y -= BASESPEED * 1*GetFrameTime();

			Bullet.x += BULLETSPEED *  GetFrameTime();
			
			if (Bullet.x < 0.0f - Bullet.width || Bullet.x > GetScreenWidth() || Bullet.y < 0.0f - Bullet.height || Bullet.y  >GetScreenHeight()) {
				SetShot(false);
			}

		}if (!Shot) {
			Bullet.x = ship.x + SQUARE+10;
			Bullet.y = ship.y + SQUARE+9;
		}
	}
	void SetShot(bool sho) {
		Shot = sho;
	}
	bool GetShot() {
		return Shot;
	}
	void DrawBullet() {
		DrawRectangleRec(Bullet, WHITE);
	}
	Rectangle GetRect() {
		return Bullet;
	}
	void UpdateBullet(Rectangle ship) {
		BulletMovement(ship);
		
	}


}