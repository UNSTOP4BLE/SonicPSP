#include "playstate.h"
#include "psp/font.h"
#include "psp/glib2d.h"

void Render_NewTile(g2dTexture* tex, Rect Tile_img, int x, int y)
{
	Rect Tile_Disp = {(x * 256) - game.camx, (y * 256) - game.camy, Tile_img.w, Tile_img.h};

	if (Playerx + Playerw >= Tile_Disp.x && 
		Playery + Playerh >= Tile_Disp.y && 
		Playerx <= Tile_Disp.x + Tile_Disp.w && 
		Playery <= Tile_Disp.y + Tile_Disp.h)
	{
		game.colliding = true;
		game.canjump = true;
	}
	else 
	{
		game.colliding = false;
		game.canjump = false;
	}
	DrawG2DTex(tex, &Tile_img, &Tile_Disp);
}