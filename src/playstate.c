#include <stdlib.h>
#include <stdio.h>
#include <pspdebug.h>
#include <pspkernel.h>
#include <psputility.h>
#include "psp/glib2d.h"
#include "psp/wav.h"
#include "psp/pad.h"
#include "playstate.h"

//include the levels
#include "levels/leveltest.h"

void Playstate() 
{
   	Wav *jump = Wav_Load("assets/sfx/SCD_FM_02.wav");
   	Wav *skidsfx = Wav_Load("assets/sfx/SCD_FM_00.wav"); 

    g2dTexture* Sonic = g2dTexLoad("assets/sonicsheet.png",G2D_SWIZZLE);
    g2dTexture* BG = g2dTexLoad("assets/bg.png",G2D_SWIZZLE);
    g2dTexture* FontTex = g2dTexLoad("assets/font.png",G2D_SWIZZLE);

    Level_TestInit();

    while(1) 
    {
       	g2dClear(GREEN);
       	Pad_Update();

 //      	if (!game.colliding)
       	//	game.gravity += 9;

       	Level_TestUpdate(skidsfx, Sonic, BG, FontTex);

		if (Pad_Pressed(PSP_CTRL_CROSS))  
        	Wav_Play(jump);

		g2dFlip(G2D_VSYNC);
    }
}

