#include "Asteroid.h"

namespace sideScroller {
	static Texture2D texture;


	static Asteroide aArray[ARRAYSIZE];


	static Rectangle origin;


	void InitAsteroid(Vector2 a1, Vector2 a2, Vector2 a3, Vector2 a4, Vector2 a5) {
		for (int i = 0; i < ARRAYSIZE; i++){
			aArray[i].x = a1.x;
			aArray[i].destroyed = false;
			aArray[i].aRotation = /*(float)GetRandomValue(0, 360)*/270.0f;
			aArray[i].rotation = 0.0f;
			aArray[i].aSpeed = 000.0f+ GetRandomValue(80, 260);
		}
		aArray[0].x = a1.x;
		aArray[0].y = a1.y;
		aArray[1].x = a2.x;
		aArray[1].y = a2.y;
		aArray[2].x = a3.x;
		aArray[2].y = a3.y;
		aArray[3].x = a4.x;
		aArray[3].y = a4.y;
		aArray[4].x = a5.x;
		aArray[4].y = a5.y;



		for (int i = 0; i < ARRAYSIZE; i++) {
			aArray[i].astRectangle = { 0, 0, 40, 40 };
		}
		Rectangle origin = { 0.0f, 0.0f, 32.0f, 32.0f };
		texture = LoadTexture("res/Mine.png");
		
	}

	void UpdateAsteroid() {
		
		
		
		for (int i = 0; i < ARRAYSIZE; i++){
			if (!aArray[i].destroyed) {
				
				aArray[i].x += aArray[i].aSpeed * sin(aArray[i].aRotation*DEG2RAD) *GetFrameTime();
				aArray[i].y -= aArray[i].aSpeed * cos(aArray[i].aRotation*DEG2RAD) *GetFrameTime();
				aArray[i].rotation += 100 * GetFrameTime();

			}
			
			

			if (aArray[i].x > screenWidth - 5.0f) {
				aArray[i].x -= screenWidth + 5.8f;
			}
			else if (aArray[i].x + 15.0f < 0.0f) {
				aArray[i].x += screenWidth  - GetRandomValue(40, 100);
				aArray[i].y = (float)GetRandomValue(10, screenHeight - 40);
			}
			if (aArray[i].y > screenHeight - 5.0f) {
				aArray[i].y -= screenHeight + 5.8f;
			}
			else if (aArray[i].y + 5.0f < 0.0f) {
				aArray[i].y += screenHeight + 5.8f;
			}

			
		}
	}


	bool AsteroidColisionRec(Rectangle r, bool bullet) {
		for (int i = 0; i < ARRAYSIZE; i++){
			Rectangle aux = { aArray[i].x - aArray[i].astRectangle.width/2 , aArray[i].y - aArray[i].astRectangle.height/2 , aArray[i].astRectangle.width+0 , aArray[i].astRectangle.height+0 };
			



			if (CheckCollisionRecs(r, aux) && !aArray[i].destroyed) {
				if (bullet) {
				SetShot(false);
			}
				DestroyAsteroid(i);
				return true;
			}
		}
		return false;
	}


	void DrawAsteroid() {
		
			Vector2 aux = { 0.0f, 0.0f };
			for (int i = 0; i < ARRAYSIZE; i++) {
				if (!aArray[i].destroyed) {
					aux = { aArray[i].astRectangle.width / 2, aArray[i].astRectangle.height / 2 };
					Rectangle aux2 = { aArray[i].x, aArray[i].y, aArray[i].astRectangle.width , aArray[i].astRectangle.height };
					DrawTexture(texture, aArray[i].x, aArray[i].y, WHITE);
				}
			}
	}
	void DestroyAsteroid(int i) {
		aArray[i].destroyed = true;
	}
	bool GetDestroyed(int i) {
		return aArray[i].destroyed;
	}
	bool AllDestroyed() {

		if (GetDestroyed(0) && GetDestroyed(1) && GetDestroyed(2) && GetDestroyed(3) && GetDestroyed(4)) {
			return true;

		}
		return false;
	}
}