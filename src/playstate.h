#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 272
#include "psp/glib2d.h"

typedef struct 
{
	int bgx;
	float gravity;
	float camx, camy;
} Game;

typedef struct 
{
	float x,y,w,h;
} Rect;

void DrawG2DTex(g2dTexture* tex, Rect *Img, Rect *Disp);

extern Game game;

void Playstate();