#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 272
#include "psp/glib2d.h"

typedef struct 
{
	int bgx;
	float gravity;
	float camx, camy;
} Game;

extern Game game;

void Playstate();