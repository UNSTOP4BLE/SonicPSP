#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 272
#include "psp/glib2d.h"

typedef struct 
{
	float gravity;
	float camx, camy;
	bool colliding;
} Game;

extern Game game;

void Playstate();