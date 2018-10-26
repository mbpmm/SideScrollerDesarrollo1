#include "play.h"
namespace sideScroller {
	static Rectangle r = { 400,225, HEIGHT, HEIGHT };
	
	static Vector2 a1 = { 380, 50 };
	static Vector2 a2 = { 550, 300 };
	static Vector2 a3 = { 200, 300 };

	
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
		InitAsteroid(a1, a2, a3);
		InitCloud();
	}
	void UpdatePlay() {
		//UpdateMusicStream(music);

		if (IsKeyPressed(KEY_SPACE)) {
			if (paused == false)paused = true;
			else paused = false;
		}
		if (!paused) {
			InputShip();
			AsteroidColisionRec(GetShip());
			UpdateAsteroid();
			UpdateCloud();
			/*
			UpdateBullet(GetShip(), GetRotation());*/
		}
		else if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
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

	}
	void DrawPlay() {
		//DrawRectangleRec(r, WHITE);
		//DrawBullet();
		DrawCloud();
		DrawAsteroid();
		
		DrawShip(0.0f);
		if (paused) {
			//StopMusicStream(music);
			DrawText(FormatText("Paused"), 250, 200, 32, DARKGRAY);
			DrawText(FormatText("Menu"), 250, 230, 32, DARKGRAY);
			
		}
		else {
			//PlayMusicStream(music);
		}
	}

}