#include "tank.h"

namespace sideScroller {
	static Texture2D texture;


	static Tank tArray[ARRAYSIZE];


	static Rectangle origin;


	void InitTank(Vector2 t1, Vector2 t2, Vector2 t3, Vector2 t4, Vector2 t5) {
		for (int i = 0; i < ARRAYSIZE; i++) {
			tArray[i].x = t1.x;
			tArray[i].destroyedT = false;
			tArray[i].tSpeed = 80.0f;
		}
		tArray[0].x = t1.x;
		tArray[0].y = t1.y;
		tArray[1].x = t2.x;
		tArray[1].y = t2.y;
		tArray[2].x = t3.x;
		tArray[2].y = t3.y;
		tArray[3].x = t4.x;
		tArray[3].y = t4.y;
		tArray[4].x = t5.x;
		tArray[4].y = t5.y;



		for (int i = 0; i < ARRAYSIZE; i++) {
			tArray[i].tRectangle = { 0, 0, 40, 40 };
		}
		Rectangle origin = { 0.0f, 0.0f, 32.0f, 32.0f };
		texture = LoadTexture("res/tank.png");

	}

	void UpdateTank() {



		for (int i = 0; i < ARRAYSIZE; i++) {
			if (!tArray[i].destroyedT) {

				tArray[i].x -= tArray[i].tSpeed *GetFrameTime();

			}

			if (tArray[i].x > 2500) {
				tArray[i].x += screenWidth + 5.8f;
			}
			else if (tArray[i].x + 15.0f < 0.0f) {
				tArray[i].x +=GetRandomValue(screenWidth,1200);
			}
			


		}
	}


	bool TankColisionRec(Rectangle r, bool bullet) {
		for (int i = 0; i < ARRAYSIZE; i++) {
			Rectangle aux = { tArray[i].x - tArray[i].tRectangle.width / 2 , tArray[i].y - tArray[i].tRectangle.height / 2 , tArray[i].tRectangle.width + 0 , tArray[i].tRectangle.height + 0 };

			if (CheckCollisionRecs(r, aux) && !tArray[i].destroyedT) {
				if (bullet) {
					SetShotBomb(false);
					SetShotBomb(true);
				}
				DestroyTank(i);
				return true;
			}
		}
		return false;
	}


	void DrawTank() {

		Vector2 aux = { 0.0f, 0.0f };
		for (int i = 0; i < ARRAYSIZE; i++) {
			if (!tArray[i].destroyedT) {
				aux = { tArray[i].tRectangle.width / 2, tArray[i].tRectangle.height / 2 };
				Rectangle aux2 = { tArray[i].x, tArray[i].y, tArray[i].tRectangle.width , tArray[i].tRectangle.height };
				DrawTexture(texture, tArray[i].x, tArray[i].y, WHITE);
			}
		}
	}
	void DestroyTank(int i) {
		tArray[i].destroyedT = true;
	}
	bool GetDestroyedTank(int i) {
		return tArray[i].destroyedT;
	}
	bool AllDestroyedTank() {

		if (GetDestroyedTank(0) && GetDestroyedTank(1) && GetDestroyedTank(2) && GetDestroyedTank(3) && GetDestroyedTank(4)) {
			return true;

		}
		return false;
	}

	Rectangle GetTank() {
		for (int i = 0; i < ARRAYSIZE; i++) {
			return tArray[i].tRectangle;
		}
	}
}