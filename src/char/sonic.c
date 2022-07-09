#include <stdlib.h>
#include <stdio.h>
#include "../psp/glib2d.h"
#include "../psp/wav.h"
#include "../psp/pad.h"
#include "../animation.h"
#include "../playstate.h"

bool sonicfacingright = true;
static int anim, animspeed = 0;

/*
static AnimFrames runstarasdasdasdt[13] = 
{
 	{  8, 42, 26, 37,  6, 0},
 	{ 37, 42, 27, 37,  6, 0},
 	{ 65, 42, 31, 38,  5, 0},
 	{ 97, 42, 37, 37,  2, 0},
 	{135, 42, 32, 35,  4, 0},
 	{170, 41, 32, 38,  6, 0},
 	{206, 41, 26, 38,  6, 0},
 	{238, 42, 24, 37,  6, 0},
 	{263, 42, 30, 37,  4, 0},
 	{295, 42, 36, 37,  0, 0},
 	{334, 42, 32, 36,  2, 0},
 	{370, 41, 29, 38,  2, 0},
 	//{  8, 42, 26, 37,  6, 0}, //put a double first frame cus it doesnt work well if u dont
};
	*/
static AnimFrames idle[2] = 
{
 	{ 1, 1, 29, 39,  0, 0},
	{ 1, 1, 29, 39,  0, 0},
};
static AnimFrames lookup[3] = 
{
 	{211, 1, 29, 38,  0, 1},
	{241, 1, 29, 38,  0, 1},
	{241, 1, 29, 38,  0, 1},
};
static AnimFrames runstart[7] = 
{
 	{238, 42, 24, 37,  6, 0},
 	{295, 42, 36, 37,  0, 0},
 	{370, 41, 29, 38,  2, 0},
 	{ 37, 42, 27, 37,  6, 0},
 	{ 97, 42, 37, 37,  2, 0},
 	{170, 41, 32, 38,  6, 0},
 	{170, 41, 32, 38,  6, 0},
};

void Char_Sonic(g2dTexture* Sonic)
{
	//if sonic is facing right keep his animations normal
	if (Pad_Held(PSP_CTRL_RIGHT))	
	{
		PlayAnim(Sonic, runstart, 1, game.gravity, 4, 6, 1, false, &anim, &animspeed);
		sonicfacingright = true;
	}
	else if (Pad_Held(PSP_CTRL_UP) && sonicfacingright)
		PlayAnim(Sonic, lookup, 5, game.gravity, 4, 2, 2, false, &anim, &animspeed);
	else if (sonicfacingright && !Pad_Held(PSP_CTRL_RIGHT) && !Pad_Held(PSP_CTRL_LEFT)) 
		PlayAnim(Sonic, idle, 5, game.gravity, 1, 1, 1, false, &anim, &animspeed);
	
	//if sonic is facing left flip his animations
	else if (Pad_Held(PSP_CTRL_LEFT))	
	{
		PlayAnim(Sonic, runstart, 37, game.gravity, 4, 6, 1, true, &anim, &animspeed);
		sonicfacingright = false;
	}
	else if (Pad_Held(PSP_CTRL_UP) && !sonicfacingright)
		PlayAnim(Sonic, lookup, 5 + 31, game.gravity, 4, 2, 2, true, &anim, &animspeed);
	else if (sonicfacingright == false && !Pad_Held(PSP_CTRL_RIGHT) && !Pad_Held(PSP_CTRL_LEFT))
		PlayAnim(Sonic, idle, 5 + 31, game.gravity, 1, 1, 1, true, &anim, &animspeed);
	
}