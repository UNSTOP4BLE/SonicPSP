#include <stdlib.h>
#include <stdio.h>
#include <pspdebug.h>
#include <pspkernel.h>
#include <psputility.h>
#include "psp/pad.h"
#include "psp/wav.h"
#include "psp/glib2d.h"
#include "psp/callbacks.h"
#include "playstate.h"

PSP_MODULE_INFO("PSP GAME", 0, 1, 0);

int main() 
{
    setupcallbacks();
	Wav_Init();
	Pad_Init();
    pspDebugScreenInit();
  	
    Playstate();
    
}