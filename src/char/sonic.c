#include <stdlib.h>
#include <stdio.h>
#include "../psp/glib2d.h"
#include "../psp/wav.h"
#include "../psp/pad.h"
#include "../animation.h"
#include "../playstate.h"

bool sonicfacingright = true;
bool skidding;
int skidtimer;
int sprinttimer;
static int anim, animspeed;
static float movespeed, playerx;

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
static AnimFrames skid[3] = 
{
 	{31, 341, 31, 36,  0, 1},
	{64, 341, 31, 36,  0, 1},
	{64, 341, 31, 36,  0, 1},
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
static AnimFrames midsprint[5] = 
{
 	{111, 200, 31, 36,  0, 0},
 	{ 74, 201, 31, 35,  0, 1},
 	{149, 201, 30, 35,  1, 1},
 	{186, 200, 31, 36,  0, 0},
 	{186, 200, 31, 36,  0, 0},
};
static AnimFrames fullsprint[5] = 
{
 	{ 71, 248, 40, 31,  0, 8},
 	{123, 247, 39, 32,  1, 7},
 	{172, 248, 39, 31,  1, 8},
 	{218, 247, 38, 32,  2, 7},
 	{218, 247, 38, 32,  2, 7},
};

void Char_Sonic(g2dTexture* Sonic, Wav *skidsound)
{
	//dear god this sucks
	if (sonicfacingright)
		game.camx += movespeed;	
	else
		game.camx -= movespeed;	
	game.camy = game.gravity;

	//control sonics movement
	if (!(Pad_Held(PSP_CTRL_LEFT) && Pad_Held(PSP_CTRL_RIGHT)))
	{
		if (sonicfacingright)
			playerx -= movespeed;
		else
			playerx += movespeed;
		
	
		if ((Pad_Held(PSP_CTRL_RIGHT) || Pad_Held(PSP_CTRL_LEFT)) && movespeed <= 8)	
		{	
			movespeed += 0.1;
			sprinttimer ++;
		}	
		else if (movespeed > 0)
			movespeed -= 0.3;
		else
			sprinttimer = 0;

		if ((sonicfacingright && movespeed >= 2 && Pad_Pressed(PSP_CTRL_LEFT)) || (!sonicfacingright && movespeed >= 2 && Pad_Pressed(PSP_CTRL_RIGHT)))
		{
			skidding = true;
		}

		if (skidding)
		{
			skidtimer ++;	
	
			if (skidtimer <= 12)
			{
				movespeed -= 4;
				if (skidtimer == 4)
					Wav_Play(skidsound);
			}
			else
			{
				skidding = false;
				skidtimer = 0;
			}

			if (sonicfacingright)
				PlayAnim(Sonic, skid, 5 + playerx + game.camx + SCREEN_WIDTH / 2 - 15, game.gravity + (SCREEN_HEIGHT / 2 - 36), 4, 2, 1, false, &anim, &animspeed);
			else
				PlayAnim(Sonic, skid, 5 + 31 + playerx + game.camx + SCREEN_WIDTH / 2 - 15, game.gravity + (SCREEN_HEIGHT / 2 - 36), 4, 2, 1, true, &anim, &animspeed);
		}
	}
	else
	{
		movespeed = 0;
		skidding = false;
		skidtimer = 0;
	}

	if (movespeed <= 0)
		movespeed = 0;

	if (!skidding)
	{
		skidtimer = 0;
		//if sonic is facing right keep his animations normal
		if (Pad_Held(PSP_CTRL_RIGHT) && !Pad_Held(PSP_CTRL_LEFT) && movespeed < 4)	
		{
			PlayAnim(Sonic, runstart, 1 + playerx + game.camx + SCREEN_WIDTH / 2 - 15, game.gravity + (SCREEN_HEIGHT / 2 - 36), 4, 6, 1, false, &anim, &animspeed);
			sonicfacingright = true;
		}
		else if (Pad_Held(PSP_CTRL_RIGHT) && !Pad_Held(PSP_CTRL_LEFT) && movespeed >= 4 && movespeed < 7)
			PlayAnim(Sonic, midsprint, 5 + playerx + game.camx + SCREEN_WIDTH / 2 - 15, game.gravity + (SCREEN_HEIGHT / 2 - 36), 3, 4, 1, false, &anim, &animspeed);
		else if (Pad_Held(PSP_CTRL_RIGHT) && !Pad_Held(PSP_CTRL_LEFT) && movespeed >= 7)
			PlayAnim(Sonic, fullsprint, playerx + game.camx + SCREEN_WIDTH / 2 - 15, game.gravity + (SCREEN_HEIGHT / 2 - 36), 4, 4, 1, false, &anim, &animspeed);
		else if (!Pad_Held(PSP_CTRL_LEFT) && !Pad_Held(PSP_CTRL_RIGHT) && movespeed != 0 && sonicfacingright)	
			PlayAnim(Sonic, runstart, 1 + playerx + game.camx + SCREEN_WIDTH / 2 - 15, game.gravity + (SCREEN_HEIGHT / 2 - 36), 8, 6, 1, false, &anim, &animspeed);
		else if (Pad_Held(PSP_CTRL_UP) && sonicfacingright && movespeed <= 3)
			PlayAnim(Sonic, lookup, 5 + playerx + game.camx + SCREEN_WIDTH / 2 - 15, game.gravity + (SCREEN_HEIGHT / 2 - 36), 4, 2, 2, false, &anim, &animspeed);
		else if (sonicfacingright && !Pad_Held(PSP_CTRL_RIGHT) && !Pad_Held(PSP_CTRL_LEFT) && movespeed == 0) 
			PlayAnim(Sonic, idle, 5 + playerx + game.camx + SCREEN_WIDTH / 2 - 15, game.gravity + (SCREEN_HEIGHT / 2 - 36), 1, 1, 1, false, &anim, &animspeed);

		//if sonic is facing left flip his animations
		else if (Pad_Held(PSP_CTRL_LEFT) && !Pad_Held(PSP_CTRL_RIGHT) && movespeed < 4)	
		{
			PlayAnim(Sonic, runstart, 37 + playerx + game.camx + SCREEN_WIDTH / 2 - 15, game.gravity + (SCREEN_HEIGHT / 2 - 36), 4, 6, 1, true, &anim, &animspeed);
			sonicfacingright = false;
		}
		else if (Pad_Held(PSP_CTRL_LEFT) && !Pad_Held(PSP_CTRL_RIGHT) && movespeed >= 4 && movespeed < 7)
			PlayAnim(Sonic, midsprint, 5 + 31 + playerx + game.camx + SCREEN_WIDTH / 2 - 15, game.gravity + (SCREEN_HEIGHT / 2 - 36), 3, 4, 1, true, &anim, &animspeed);
		else if (Pad_Held(PSP_CTRL_LEFT) && !Pad_Held(PSP_CTRL_RIGHT) && movespeed >= 7)
			PlayAnim(Sonic, fullsprint, 5 + 31 + playerx + game.camx + SCREEN_WIDTH / 2 - 15, game.gravity + (SCREEN_HEIGHT / 2 - 36), 4, 4, 1, true, &anim, &animspeed);
		else if (!Pad_Held(PSP_CTRL_LEFT) && !Pad_Held(PSP_CTRL_RIGHT) && movespeed != 0 && !sonicfacingright)	
			PlayAnim(Sonic, runstart, 37 + playerx + game.camx + SCREEN_WIDTH / 2 - 15, game.gravity + (SCREEN_HEIGHT / 2 - 36), 8, 6, 1, true, &anim, &animspeed);
		else if (Pad_Held(PSP_CTRL_UP) && !sonicfacingright && movespeed <= 3)
			PlayAnim(Sonic, lookup, 5 + 31 + playerx + game.camx + SCREEN_WIDTH / 2 - 15, game.gravity + (SCREEN_HEIGHT / 2 - 36), 4, 2, 2, true, &anim, &animspeed);
		else if (sonicfacingright == false && !Pad_Held(PSP_CTRL_RIGHT) && !Pad_Held(PSP_CTRL_LEFT) && movespeed == 0)
			PlayAnim(Sonic, idle, 5 + 31 + playerx + game.camx + SCREEN_WIDTH / 2 - 15, game.gravity + (SCREEN_HEIGHT / 2 - 36), 1, 1, 1, true, &anim, &animspeed);

		//dont break anims when left and right are pressed at the same time
		if (Pad_Held(PSP_CTRL_LEFT) && Pad_Held(PSP_CTRL_RIGHT) && sonicfacingright)	
			PlayAnim(Sonic, idle, 5 + playerx + game.camx + SCREEN_WIDTH / 2 - 15, game.gravity + (SCREEN_HEIGHT / 2 - 36), 1, 1, 1, false, &anim, &animspeed);
		if (Pad_Held(PSP_CTRL_LEFT) && Pad_Held(PSP_CTRL_RIGHT) && !sonicfacingright)	
			PlayAnim(Sonic, idle, 5 + 31 + playerx + game.camx + SCREEN_WIDTH / 2 - 15, game.gravity + (SCREEN_HEIGHT / 2 - 36), 1, 1, 1, true, &anim, &animspeed);
	}
}