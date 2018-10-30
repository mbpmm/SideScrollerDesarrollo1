#include "gameState.h"
namespace sideScroller
{


	int screenWidth = 0;
	int screenHeight = 0;
	int score1 = 0;
	int gameState = Start;

	int verMajor = 0;

	float verMinor = 8.2f;

	static void InitGame() {
		screenWidth = 800;
		screenHeight = 400;
		InitWindow(screenWidth, screenHeight, "SideScroller");
		//InitAudioDevice();
		SetExitKey(0);
		int gameState = Start;

		int score = 0;

	}
	void PlayGame() {
//inits
		InitGame();
		InitPlay();
		while (!WindowShouldClose() && gameState != End) {
			UpdateGame();
			DrawGame();
		}
	}

	static void UpdateGame() {
		
		switch (gameState) {
		case Start: {
			UpdateStart();
			
		}break;
		case Play: {

			UpdatePlay();

		}break;
		case GameOver: {

		}break;
		case Credit: {
			UpdateCredit();

		}break;
		case End: {

		}break;
		}
	}
	static void DrawGame() {
		BeginDrawing();
		ClearBackground(BLACK);
		switch (gameState) {
		case Start: {
			DrawStart();
		}break;
		case Play: {

			DrawPlay();

		}break;
		case GameOver: {

		}break;
		case Credit: {
			DrawCredit();

		}break;
		case End: {
			//UnloadMusicStream(music);   // Unload music stream buffers from RAM
			//CloseAudioDevice();

		}break;
		}


		EndDrawing();
	}

}