#include <stdlib.h>
#include <stdio.h>
#include "../psp/glib2d.h"
#include "../psp/wav.h"
#include "../psp/pad.h"
#include "../animation.h"

static AnimFrames idle[] = 
{
 	{ 1, 1, 29, 39},
};
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
	PlayAnim(Sonic, runstart, 1, 1, 4, 6, 0);
	//g2dTexFree(Sonic)


}