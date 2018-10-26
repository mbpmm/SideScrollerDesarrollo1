#include "credit.h"

namespace sideScroller {
	static int verMajor = 0;

	static float verMinor = 8.2;

	void UpdateCredit() {
	
		Vector2 aux = { GetMousePosition().x, GetMousePosition().y };
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			if (aux.x > 55 && aux.x < 255 && aux.y >280 && aux.y < 320) {
			gameState = Start;
			}
		
		}
	}
	void DrawCredit(){
		DrawText(FormatText("Made by: Ariel Plomer"), 75, 75, 32, WHITE);
		DrawText(FormatText("Version: v%i.%f", verMajor, verMinor), 75, 120, 32, WHITE);
		DrawText(FormatText("Used Kenney backgroud elements", verMajor, verMinor), 75, 165, 32, WHITE);
		DrawRectangle(55, screenHeight - 130, 110, 50, WHITE);
		DrawText(FormatText("Menu"), 75, 280, 32, DARKGRAY);
	
	}



}