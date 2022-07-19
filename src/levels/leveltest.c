#include <stdio.h> 
#include "../playstate.h"
#include "../char/sonic.h"
#include "../psp/glib2d.h"
#include "../psp/wav.h"
#include "../psp/pad.h"
#include "../psp/font.h"

#include "leveltest.h"
#include "../char/sonic.h"

char debugmsg[1000];
static void DrawBg(g2dTexture* BG, int x, float camx);
static void DrawFloorPiece(g2dTexture* BG, int x, int y);

void Level_TestInit() //this code will execute only once
{
   	Wav *ghz = Wav_Load("assets/sfx/greenhill.wav"); 
    Wav_SetLoop(ghz, 7);
    Wav_Play(ghz);
}

void Level_TestUpdate(Wav *skidsfx, g2dTexture* Sonic, g2dTexture* BG, g2dTexture* FontTex) //this code will execute every frame
{
	for (int i = 0; i < 10; i++) // spawn 10 backgrounds, its not a perfomance issue right????
    {
    	DrawBg(BG, (544 + 208) * i, game.camx / 2);
    	DrawFloorPiece(BG, 255 * i, 130);
    }

	Char_Sonic(Sonic, skidsfx); // spawns sonic

	sprintf(debugmsg, "bgx %d camx %f", game.bgx, game.camx);
    PrintMSG(FontTex, debugmsg, 0, 0);
}

static void DrawBg(g2dTexture* BG, int x, float camx)
{
   	Rect Back_img = {1, 0, 510, 240};
  	Rect Back2_img = {1, 241, 174, 240};
   	Rect Back_Disp = {x - camx, 0, 544, SCREEN_HEIGHT + 1};
   	Rect Back2_Disp = {x + 544 - camx, 0, 208, SCREEN_HEIGHT + 1};
   	DrawG2DTex(BG, &Back_img, &Back_Disp);
   	DrawG2DTex(BG, &Back2_img, &Back2_Disp);
}

static void DrawFloorPiece(g2dTexture* BG, int x, int y)
{
   	Rect Pattern_img = {255, 491, 256, 20};
   	Rect Pattern_Disp = {x - game.camx, y + 48 - game.camy, 256, 20};

   	Rect FloorP_img = {255, 443, 256, 68};
   	Rect FloorP_Disp = {x - game.camx, y - game.camy, 256, 68};
   	DrawG2DTex(BG, &FloorP_img, &FloorP_Disp);
   	for (int i = 0; i < 6; i++)	
	{
		Pattern_Disp.y *= i;
   		DrawG2DTex(BG, &Pattern_img, &Pattern_Disp);
   	}
}

