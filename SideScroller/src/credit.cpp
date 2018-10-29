#include "credit.h"

namespace sideScroller {


	void UpdateCredit() {
	
		Vector2 aux = { GetMousePosition().x, GetMousePosition().y };
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			if (aux.x > 55 && aux.x < 255 && aux.y >280 && aux.y < 320) {
			gameState = Start;
			}
		
		}
	}
	void DrawCredit(){
		DrawText("Made by: Ariel Plomer", 75, 75, 32, WHITE);
		DrawText(FormatText("Version: v%i.%f", verMajor, verMinor), 75, 120, 32, WHITE);
		DrawText("Used Kenney backgroud elements", 75, 165, 32, WHITE);
		DrawRectangle(55, screenHeight - 130, 110, 50, WHITE);
		DrawText("Menu", 75, 280, 32, DARKGRAY);
	
	}



}