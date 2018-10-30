#include "play.h"
namespace sideScroller {
	static Rectangle r = { 400,225, HEIGHT, HEIGHT };
	
	static Vector2 a1 = { 380, 50 };
	static Vector2 a2 = { 550, 300 };
	static Vector2 a3 = { 200, 300 };
	static Vector2 a4 = { 180, 0 };
	static Vector2 a5 = { 480, 0 };
	/*
	Music music;
	static float rotation = 0.0f;
	*/

	int BASESPEED = 80;
	static bool paused = false;

	void InitPlay() {
		//music = LoadMusicStream("res/Music.ogg");
		//PlayMusicStream(music);
		InitShip();
		InitAsteroid(a1, a2, a3, a4, a5);
		InitCloud();
	}
	void UpdatePlay() {
		//UpdateMusicStream(music);
		
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && (GetMouseX() > screenWidth - 150) && (GetMouseX() < screenWidth - 114)
			&& (GetMouseY() > 0) && (GetMouseY() < + 32)) {
			if (paused == false)paused = true;
			else paused = false;
		}
		if (!paused) {
			InputShip();
			AsteroidColisionRec(GetShip(), false);
			if (GetShot())
				AsteroidColisionRec(GetRect(), true);
			UpdateAsteroid();
			UpdateCloud();

			UpdateBullet(GetShip());
			UpdateBomb(GetShip());
		}
		else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && (GetMouseX() < 330) && (GetMouseX() > 250)
			&& (GetMouseY() < 250) && (GetMouseY() > 230)
			) {
			gameState = Start;


			/*
			Vector2 aux = { GetMousePosition().x, GetMousePosition().y };
			if (aux.x > 250 && aux.x < 360 && aux.y >200 && aux.y < 250) {
				paused = false;
			}
			if (aux.x > 250 && aux.x < 360 && aux.y >230 && aux.y < 280) {
				gameState = Start;

			}*/

		}
			if (AllDestroyed()) {
				gameState = End;
			}
	}
	void DrawPlay() {
		DrawCloud();
		DrawAsteroid();
		DrawBullet();
		DrawBomb();
		DrawShip(0.0f);
		
		if (paused) {
			//StopMusicStream(music);
			//DrawText("Paused", 250, 200, 32, DARKGRAY);
			DrawText("Menu", 250, 230, 32, DARKGRAY);
			DrawText("unPause", screenWidth - 150, 00, 16, DARKGRAY);
		}
		else {
			DrawText("Pause", screenWidth - 150, 00, 16, DARKGRAY);
			//PlayMusicStream(music);
		}
	}

}