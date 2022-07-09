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

void Playstate() 
{
   	Wav *jump = Wav_Load("assets/sfx/SCD_FM_02.wav"); 
    g2dTexture* Sonic = g2dTexLoad("assets/sonicsheet.png",G2D_SWIZZLE);

    while(1) 
    {
       	g2dClear(GREEN);
       	Pad_Update();
		Char_Sonic(Sonic);

		if (Pad_Pressed(PSP_CTRL_CROSS))  
        	Wav_Play(jump);

		g2dFlip(G2D_VSYNC);
    }
}