#include <stdlib.h>
#include <stdio.h>
#include "psp/glib2d.h"
#include "animation.h"

static int anim;
static int animspeed;

void InitAnim(g2dTexture* tex, AnimFrames Frames, int animx, int animy)
{
    g2dBeginRects(tex);
	g2dSetCropXY(Frames.x, Frames.y);
	g2dSetCropWH(Frames.w, Frames.h);
	g2dSetScaleWH(Frames.w, Frames.h);
	g2dSetCoordXY(Frames.offsetx + animx, Frames.offsety + animy);
	g2dAdd();
}

void PlayAnim(g2dTexture* tex, AnimFrames Frames[], int animx, int animy, int animcooldown, int lastframe, int backframe)
{
	if (anim > lastframe - 1) // we do -1 cus the frames are a array
		anim = backframe;
	animspeed ++;
	if (animspeed > animcooldown)
	{
		anim += 1;
		animspeed = 0;
	}

	
    InitAnim(tex, Frames[anim], animx, animy);
}


