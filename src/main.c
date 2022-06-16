#include <stdlib.h>
#include <stdio.h>
#include <pspdebug.h>
#include <pspkernel.h>
#include <psputility.h>
#include "psp/glib2d.h"
#include "psp/wav.h"
#include "psp/pad.h"
#include "animation.h"
#include "char/sonic.h"

PSP_MODULE_INFO("PSP GAME", 0, 1, 0);

int exit_callback(int arg1, int arg2, void* common) {
    sceKernelExitGame();
    return 0;
}

int callbackthread(SceSize args, void* argp) {
    int cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
    sceKernelRegisterExitCallback(cbid);

    sceKernelSleepThreadCB();
    return 0;
}

void setupcallbacks() {
    int thid =sceKernelCreateThread("update_thread", callbackthread, 0x11, 0xFA0, 0, NULL );
    if (thid >= 0){
        sceKernelStartThread(thid, 0, NULL);
    }
}

int main() 
{
    setupcallbacks();
	WavInit();
	PadInit();
    pspDebugScreenInit();
   	Wav *jump = WavLoad("assets/sfx/SCD_FM_02.wav"); 
    g2dTexture* Sonic = g2dTexLoad("assets/sonicsheet.png",G2D_SWIZZLE);

    while(1) 
    {
    	PadUpdate();
    	if (PadPressed(PSP_CTRL_CROSS))  
        	WavPlay(jump);
       
        g2dClear(GREEN);
       
      
		Char_Sonic(Sonic);

		g2dEnd();
       	g2dFlip(G2D_VSYNC);

       	
    }
}