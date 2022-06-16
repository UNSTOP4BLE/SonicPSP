#ifndef	__PAD_H__
#define	__PAD_H__

#include <pspctrl.h>

typedef struct Vec2
{
	float	x, y;
} Vec2, Vec2f; 

extern bool 		PadInit		(void);
extern void			PadShutdown	(void);
extern void			PadUpdate		(void);
extern bool		    PadAny		(void);
extern bool	    	PadPressed	(const unsigned long Button);
extern bool		    PadHeld		(const unsigned long Button);
extern Vec2f*	    PadGetStick	(void);

#endif
