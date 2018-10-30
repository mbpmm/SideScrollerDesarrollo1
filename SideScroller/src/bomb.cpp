#include "bomb.h"
namespace sideScroller {

	static Vector2 BombSpeed = { 200,100 };
	static bool Shot = false;
	static Rectangle Bomb = { -100, -100, SQUARE / 2, SQUARE / 2 };
	void BombMovement(Rectangle ship) {
		if (Shot) {
			BombSpeed.x--;
			BombSpeed.y++;

			Bomb.y += BombSpeed.y * 1*GetFrameTime();

			Bomb.x -= BombSpeed.x * GetFrameTime();

			if (Bomb.x < 0.0f - Bomb.width || Bomb.x > GetScreenWidth() || Bomb.y < 0.0f - Bomb.height || Bomb.y  >GetScreenHeight()) {
				SetShotBomb(false);
				BombSpeed.x=200;
				BombSpeed.y=100;
			}

		}if (!Shot) {
			Bomb.x = ship.x + SQUARE + 10;
			Bomb.y = ship.y + SQUARE + 9;
		}
	}
	void SetShotBomb(bool sho) {
		Shot = sho;
	}
	bool GetShotBomb() {
		return Shot;
	}
	void DrawBomb() {
		DrawRectangleRec(Bomb, WHITE);
	}
	Rectangle GetRectBomb() {
		return Bomb;
	}
	void UpdateBomb(Rectangle ship) {
		BombMovement(ship);

	}


}