#include "playstate.h"
#include "psp/font.h"
#include "psp/glib2d.h"


#include <stdio.h>            
char damsg[10];
void Render_NewTile(g2dTexture* tex, Rect Tile_img, int x, int y)
{
	Rect Tile_Disp = {x * 256, y * 256, Tile_img.w, Tile_img.h};

	if (game.camx >= Tile_Disp.x && 
		game.camy >= Tile_Disp.y && 
		game.camx + 40 <= Tile_Disp.w && 
		game.camy + 40 <= Tile_Disp.h)
		game.colliding = true;
	else
		game.colliding = false;
	sprintf(damsg, "collidg %d", game.colliding);
	PrintMSG(g2dTexLoad("assets/font.png",G2D_SWIZZLE), damsg, 0, 11);
	DrawG2DTex(tex, &Tile_img, &Tile_Disp);
}