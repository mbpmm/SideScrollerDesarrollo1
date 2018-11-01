#include "tank.h"

namespace sideScroller {
	static Texture2D texture;


	static Tank tArray[ARRAYSIZE];
	static bool shot;
	static int tankSpeed = 80;
	bool bulletImpact;
	static Rectangle origin;
	static Rectangle bulletTank = {-32 ,368, SQUARE / 4, SQUARE / 4 };

	void InitTank(Vector2 t1, Vector2 t2, Vector2 t3, Vector2 t4, Vector2 t5) {
		for (int i = 0; i < ARRAYSIZE; i++) {
			tArray[i].x = t1.x;
			tArray[i].destroyedT = false;
			tArray[i].tSpeed = tankSpeed;
			tArray[i].bulletTank = bulletTank;
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
		tArray[0].bulletTank.x = t1.x;
		tArray[0].bulletTank.y = t1.y;
		tArray[1].bulletTank.x = t2.x;
		tArray[1].bulletTank.y = t2.y;
		tArray[2].bulletTank.x = t3.x;
		tArray[2].bulletTank.y = t3.y;
		tArray[3].bulletTank.x = t4.x;
		tArray[3].bulletTank.y = t4.y;
		tArray[4].bulletTank.x = t5.x;
		tArray[4].bulletTank.y = t5.y;

		shot = true;
		bulletImpact = false;
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
				shot = true;
				if (shot) {
					tArray[i].bulletTank.y -= BULLETTANKSPEED * GetFrameTime();

					tArray[i].bulletTank.x -= BULLETTANKSPEED * GetFrameTime();

					if (tArray[i].bulletTank.y < 0.0f - tArray[i].bulletTank.height || tArray[i].bulletTank.y  >GetScreenHeight()) {
						SetShotTank(false);
					}

				}if (!shot) {
					tArray[i].bulletTank.x = tArray[i].x;
					tArray[i].bulletTank.y = tArray[i].y;
				}
			}

			if (tArray[i].x > 2500) {
				tArray[i].x += screenWidth + 5.8f;
			}
			else if (tArray[i].x + 15.0f < 0.0f) {
				tArray[i].x +=GetRandomValue(screenWidth,1200);
			}
			


		}
	}

	void SetShotTank(bool sho) {
		shot = sho;
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
			if (CheckCollisionRecs(tArray[i].bulletTank, GetShip()) && !tArray[i].destroyedT) {
				gameState = End;
				bulletImpact = true;
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
				DrawRectangleRec(tArray[i].bulletTank, WHITE);
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

	Vector2 GetTank() {
		for (int i = 0; i < ARRAYSIZE; i++) {
			return { tArray[i].x-32,tArray[i].y-32 };
		}
	}
}