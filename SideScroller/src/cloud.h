#ifndef CLOUD_H
#define CLOUD_H
#include <iostream>

#include "gameState.h"
#include "play.h"
#include <math.h>
#include "raylib.h"

using namespace std;
namespace sideScroller {
#define CARRAYSIZE 10


	extern Texture2D tCArray[8];
	//extern Asteroide aArray[ARRAYSIZE];



	void InitCloud();
	void UpdateCloud();
	void DrawCloud();
};
#endif
