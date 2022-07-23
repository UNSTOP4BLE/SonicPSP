#define Playerx (SCREEN_WIDTH / 2) - 15
#define Playery (SCREEN_HEIGHT / 2) - 36
#define Playerw 35
#define Playerh 40
#include "psp/glib2d.h"


typedef struct 
{
	float gravity;
	float camx, camy;
	bool colliding, canjump;
} Game;

extern Game game;

void Playstate();