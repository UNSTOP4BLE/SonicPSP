#include <stdlib.h>
#include <stdio.h>
#include <pspdebug.h>
#include <pspkernel.h>
#include <psputility.h>
#include "psp/glib2d.h"
#include "psp/wav.h"
#include "psp/pad.h"
#include "char/sonic.h"
#include "playstate.h"

void DrawBg(g2dTexture* BG, int x, float camx);

void Playstate() 
{
   	Wav *jump = Wav_Load("assets/sfx/SCD_FM_02.wav"); 
   	Wav *skid= Wav_Load("assets/sfx/SCD_FM_00.wav"); 
    g2dTexture* Sonic = g2dTexLoad("assets/sonicsheet.png",G2D_SWIZZLE);
    g2dTexture* BG = g2dTexLoad("assets/bg.png",G2D_SWIZZLE);

    while(1) 
    {
       	g2dClear(GREEN);

       	Pad_Update();

       	//game.gravity += 9;

       	if (game.bgx < SCREEN_WIDTH)
       		Wav_Play(jump);
       	DrawBg(BG, game.bgx, game.camx / 2);
       	DrawBg(BG, game.bgx + 544 + 208, game.camx / 2);
       	//1st back
       	//2nd back
    //   	Back_Disp.x = Back_Disp.x + 544 + 208 + 1;
      //	DrawG2DTex(BG, &Back_img, &Back_Disp);
//
  //     	Back2_Disp.x = Back_Disp.x + 544;
    //   	DrawG2DTex(BG, &Back2_img, &Back2_Disp);



		Char_Sonic(Sonic, skid);

		if (Pad_Pressed(PSP_CTRL_CROSS))  
        	Wav_Play(jump);

		g2dFlip(G2D_VSYNC);
    }
}

void DrawG2DTex(g2dTexture* tex, Rect *Img, Rect *Disp)
{
	g2dBeginRects(tex);
	g2dSetCropXY(Img->x, Img->y);
	g2dSetCropWH(Img->w, Img->h);
	g2dSetCoordXY(Disp->x, Disp->y);
	g2dSetScaleWH(Disp->w, Disp->h);
	g2dAdd();
	g2dEnd();
}

void DrawBg(g2dTexture* BG, int x, float camx)
{
   	Rect Back_img = {1, 0, 510, 240};
  	Rect Back2_img = {1, 241, 174, 240};
   	Rect Back_Disp = {x - camx, 0, 544, SCREEN_HEIGHT + 1};
   	Rect Back2_Disp = {x + 544 - camx, 0, 208, SCREEN_HEIGHT + 1};
   	DrawG2DTex(BG, &Back_img, &Back_Disp);
   	DrawG2DTex(BG, &Back2_img, &Back2_Disp);
}

