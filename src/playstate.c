#include <stdlib.h>
#include <stdio.h>
#include <pspdebug.h>
#include <pspkernel.h>
#include <psputility.h>
#include "psp/glib2d.h"
#include "psp/wav.h"
#include "psp/pad.h"
#include "psp/font.h"
#include "char/sonic.h"
#include "playstate.h"

char debugmsg[1000];

static int movebg;

void DrawBg(g2dTexture* BG, int x, float camx);

void Playstate() 
{
   	Wav *jump = Wav_Load("assets/sfx/SCD_FM_02.wav"); 
   	Wav *skid= Wav_Load("assets/sfx/SCD_FM_00.wav"); 
    g2dTexture* Sonic = g2dTexLoad("assets/sonicsheet.png",G2D_SWIZZLE);
    g2dTexture* BG = g2dTexLoad("assets/bg.png",G2D_SWIZZLE);
    g2dTexture* FontTex = g2dTexLoad("assets/font.png",G2D_SWIZZLE);

    while(1) 
    {
       	sprintf(debugmsg, "bgx %d camx %f movebg %d", game.bgx, game.camx, movebg);

       	g2dClear(GREEN);
       	Pad_Update();

       	//game.gravity += 9;

       	DrawBg(BG, game.bgx, game.camx / 2);
       	DrawBg(BG, game.bgx + 544 + 208, game.camx / 2);
       
		Char_Sonic(Sonic, skid);

		if (Pad_Pressed(PSP_CTRL_CROSS))  
        	Wav_Play(jump);

		if (Pad_Held(PSP_CTRL_LEFT))  
        	movebg --;
        else if (Pad_Held(PSP_CTRL_RIGHT))  
        	movebg ++;

        PrintMSG(FontTex, debugmsg, 0, 0);
		g2dFlip(G2D_VSYNC);
    }
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

