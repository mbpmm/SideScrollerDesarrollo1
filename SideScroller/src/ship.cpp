#include "ship.h"

namespace sideScroller {
	static Rectangle _ship = { 400,225, SQUARE, SQUARE };
	static Texture2D texture;
	static float _x = -100;
	static float _y = -100;
	static Vector2 originVec = { 64,64};
	static float accelSpeed = 0.0f;
	static Vector2 vecSpeed = { 0.0f,0.0f };
	static float rotation = 0.0f;
	static Rectangle origin = { 0.0f, 0.0f,64.0f, 64.0f};

	static float shipAngle;
	static float frameCounter;
	void InitShip() {
		texture = LoadTexture("res/Ship.png");
		shipAngle = 0.0f;
		frameCounter = 0.0f;
	}
	float GetRotation(){
		return rotation;
	}

	void DrawShip(float rot) {
		Rectangle aux= {0.0f,0.0f ,originVec.x, originVec.y};
		//Rectangle aux = { originVec.x /2, originVec.y/ 3, _ship.x, _ship.y };
		//Rectangle auxa= { originVec.x, originVec.y, _ship.x, _ship.y};
		cout << shipAngle<<endl;
		if (frameCounter < 1) {
			if (shipAngle <= 0.3f&& shipAngle<=-0.3f)
				aux.y += texture.height/3;
			if(shipAngle<2 || shipAngle >-2)
				aux.y += texture.height / 3 *2;
		}
		else{
				if (shipAngle < 1 && shipAngle >2 ||(shipAngle > -1 && shipAngle <-2))
					aux.x+= texture.width / 2;
				if (shipAngle <= 0.3f&& shipAngle <= -0.3f) {
					aux.x+= texture.width / 2;
					aux.y+= texture.height / 3;

				}
				if (shipAngle < 2|| shipAngle >-2) {
					aux.x+= texture.width / 2;
					aux.y+= 2* texture.height / 3;
				}
			}

		Vector2 aux2 = { _ship.x, _ship.y};
		//DrawTexturePro(texture,origin, aux, aux2, rotation, WHITE);
		//DrawRectanglePro(aux, aux2, 0.0f, WHITE);
		//DrawTexturePro(texture,origin,auxa,aux2,rot,WHITE);


		DrawTextureRec(texture, aux, aux2, WHITE);
	}

	void InputShip() {
		frameCounter += GetFrameTime();
		if (frameCounter > 3) {
			frameCounter = 0.0f;
		}

		if (shipAngle < 0)
			shipAngle += 10*GetFrameTime();
		else
			shipAngle -= 10*GetFrameTime();

		if(IsKeyDown(KEY_W)){
			_ship.y -= 50.0f*GetFrameTime();
			if(shipAngle<3)
			shipAngle += 50.0f*GetFrameTime();
		}
		if (IsKeyDown(KEY_D)) {
			_ship.x -= 50.0f*GetFrameTime();
			
		}
		if (IsKeyDown(KEY_S)) {
			_ship.y += 50.0f*GetFrameTime();
			if (shipAngle>-3)
			shipAngle -= 50.0f*GetFrameTime();
		}

		/*
		
		Vector2 mousePos = GetMousePosition();
		Vector2 dir = { _ship.x - mousePos.x, _ship.y - mousePos.y };

		float moduloDir = sqrt(pow(dir.x, 2) + pow(dir.y, 2));
		
		if (moduloDir > 0.0f){
			rotation = acos((_ship.y - mousePos.y) / moduloDir) / DEG2RAD;
		}

		if (_ship.x > mousePos.x) {
			rotation = 360 - rotation;
		}

		vecSpeed.x = sin(rotation*DEG2RAD) *GetFrameTime();
		vecSpeed.y = cos(rotation*DEG2RAD) *GetFrameTime();

		if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
			if (accelSpeed < 2) accelSpeed += 0.04f;
		}
		//else if (accelSpeed > 0)accelSpeed -= 0.0004f;
		else if (accelSpeed < 0) accelSpeed = 0;


		
		_ship.x += vecSpeed.x * accelSpeed* BASESPEED;
		_ship.y -= vecSpeed.y * accelSpeed* BASESPEED;

		
		if (_ship.x > screenWidth-5.0f) {
			_ship.x -= screenWidth+5.1f; 
		}
		else if (_ship.x +5.0f < 0.0f) {
			_ship.x += screenWidth+5.1f;
		}
		if (_ship.y > screenHeight- 5.0f) {
			_ship.y -= screenHeight + 5.1f;
		}
		else if (_ship.y + 5.0f < 0.0f) {
			_ship.y += screenHeight + 5.1f;
		}*/
	}
	void UnloadShip() {
		UnloadTexture(texture);
	}
	Rectangle GetShip() {
		return _ship;
	}
}