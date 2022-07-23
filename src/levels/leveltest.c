#include <stdio.h> 
#include "../playstate.h"
#include "../char/sonic.h"
#include "../psp/glib2d.h"
#include "../psp/wav.h"
#include "../psp/pad.h"
#include "../psp/font.h"
#include "../tilerenderer.h"

#include "leveltest.h"
#include "../char/sonic.h"

char debugmsg[1000];
static void DrawBg(g2dTexture* BG, int x, float camx);
static void DrawFloorPiece(g2dTexture* BG, int x, int y);

void Level_TestInit() //this code will execute only once
{
   	Wav *ghz = Wav_Load("assets/sfx/greenhill.wav"); 
    Wav_SetLoop(ghz, 1);
    Wav_Play(ghz);
}

void Level_TestUpdate(Wav *skidsfx, g2dTexture* Sonic, g2dTexture* BG, g2dTexture* FontTex) //this code will execute every frame
{
	for (int i = 0; i < 10; i++) // spawn 10 backgrounds, its not a perfomance issue right????
    {
    	if (i <= 1) // spawn only 2 bg parts cus u wont see the others anyways
    		DrawBg(BG, (544 + 208) * i, game.camx / 5);
    	DrawFloorPiece(BG, 256 * i, 130);
    }

    Rect a_img = {1, 0, 510, 240};
    Render_NewTile(BG, a_img, 2, 1);
    Render_NewTile(BG, a_img, 3, 1);
	Char_Sonic(Sonic, skidsfx); // spawns sonic

	sprintf(debugmsg, "camx %f, coll %d", game.camx, game.colliding);
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

}

