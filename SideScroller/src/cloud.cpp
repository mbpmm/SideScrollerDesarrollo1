#include "cloud.h"
namespace sideScroller {
	static Nubes cArray[CARRAYSIZE];
	
	Texture2D tCArray[8];

	void InitCloud() {

		tCArray[0] = LoadTexture("res/cloud1.png");
		tCArray[1] = LoadTexture("res/cloud2.png");
		tCArray[2] = LoadTexture("res/cloud3.png");
		tCArray[3] = LoadTexture("res/cloud4.png");
		tCArray[4] = LoadTexture("res/cloud5.png");
		tCArray[5] = LoadTexture("res/cloud6.png");
		tCArray[6] = LoadTexture("res/cloud7.png");
		tCArray[7] = LoadTexture("res/cloud8.png");
		for (int i = 0; i < CARRAYSIZE; i++) {
			cArray[i].x = (float)GetRandomValue(screenWidth / CARRAYSIZE * i, (screenWidth/CARRAYSIZE*(i+1))-50);
			cArray[i].y = (float)GetRandomValue(50,screenHeight-70);
			cArray[i].texture = tCArray[GetRandomValue(0,8)];
			cArray[i].scale = (float)GetRandomValue(40, 80)/100;
			cArray[i].cSpeed = 40.0f/ cArray[i].scale;
		}


	}
	void UpdateCloud() {
		for (int i = 0; i < CARRAYSIZE; i++) {
			cArray[i].x -= cArray[i].cSpeed * GetFrameTime();
		

			if (cArray[i].x > screenWidth - 0.0f) {
				cArray[i].scale = (float)GetRandomValue(20, 100) / 100;
				cArray[i].x -= screenWidth + 450.0f* cArray[i].scale +GetRandomValue(-100,-50);
				cArray[i].y = (float)GetRandomValue(50, screenHeight - 70);
			}
		
		
		}

	}
	void DrawCloud() {
		for (int i = 0; i < CARRAYSIZE; i++) {
			Vector2 aux = { (int)cArray[i].x, (int)cArray[i].y};
			//DrawTexture(cArray[i].texture, (int)cArray[i].x, (int)cArray[i].y, WHITE);
			DrawTextureEx(cArray[i].texture, aux, 0.0f, cArray[i].scale, WHITE);
		}
	}
};