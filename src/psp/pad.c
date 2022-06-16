#include <string.h>
#include <pspctrl.h>
#include <stdbool.h>

#include "pad.h"

typedef struct Input
{
	SceCtrlData	  Input;
	Vec2f		  Stick;
	unsigned long Pressed;
	unsigned long Held;
} Input;

static Input Pad;

static void AddInput (const unsigned long Button)
{
	if ((Pad.Input.Buttons & Button) != 0)	// Button is down
	{
		if ((Pad.Held & Button) == 0)			// Held is not TRUE
		{
			Pad.Pressed	|= Button;			// so set both Pressed
			Pad.Held	|= Button;			// and Held to TRUE
		}
	}
	else										// Button is up
	{
		Pad.Pressed	&= ~Button;				// so set Presses
		Pad.Held	&= ~Button;				// and Held to FALSE
	}
}

bool PadInit (void)
{
	memset (&Pad, 0, sizeof(Input));

	sceCtrlSetSamplingCycle (0);

	sceCtrlSetSamplingMode (PSP_CTRL_MODE_ANALOG);

	return 1;
}

void PadUpdate (void)
{
	sceCtrlPeekBufferPositive (&Pad.Input, 1);

	if (Pad.Input.Lx > 103 && Pad.Input.Lx < 151)	Pad.Stick.x	= 0.0f;
	else												Pad.Stick.x	= (Pad.Input.Lx - 128.0f) / 128.0f;

	if (Pad.Input.Ly > 103 && Pad.Input.Ly < 151)	Pad.Stick.y	= 0.0f;
	else												Pad.Stick.y	= (Pad.Input.Ly - 128.0f) / 128.0f;

	AddInput (PSP_CTRL_SELECT);
	AddInput (PSP_CTRL_START);
	AddInput (PSP_CTRL_UP);
	AddInput (PSP_CTRL_RIGHT);
	AddInput (PSP_CTRL_DOWN);
	AddInput (PSP_CTRL_LEFT);
	AddInput (PSP_CTRL_LTRIGGER);
	AddInput (PSP_CTRL_RTRIGGER);
	AddInput (PSP_CTRL_TRIANGLE);
	AddInput (PSP_CTRL_CIRCLE);
	AddInput (PSP_CTRL_CROSS);
	AddInput (PSP_CTRL_SQUARE);
}

bool PadPressed (const unsigned long Button)
{
	if (((Pad.Pressed & Button) != 0))	// Pressed is TRUE
	{
		Pad.Pressed	&= ~Button;			// so set it to FALSE
		return 1;						// and return TRUE
	}

	return 0;
}

bool PadHeld (const unsigned long Button)
{
	return	((Pad.Held & Button) != 0);
}

bool PadAny (void)
{
	if (PadPressed (PSP_CTRL_SELECT)	||
		PadPressed (PSP_CTRL_START)	    ||
		PadPressed (PSP_CTRL_UP)		||
		PadPressed (PSP_CTRL_RIGHT)	    ||
		PadPressed (PSP_CTRL_DOWN)		||
		PadPressed (PSP_CTRL_LEFT)		||
		PadPressed (PSP_CTRL_LTRIGGER)	||
		PadPressed (PSP_CTRL_RTRIGGER)	||
		PadPressed (PSP_CTRL_TRIANGLE)	||
		PadPressed (PSP_CTRL_CIRCLE)	||
		PadPressed (PSP_CTRL_CROSS)	    ||
		PadPressed (PSP_CTRL_SQUARE))
		return 1;

	return 0;
}

Vec2f* PadGetStick (void)
{
	return &Pad.Stick;
}
