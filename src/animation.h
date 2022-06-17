typedef struct
{
	int x, y, w, h, offsetx, offsety;
} AnimFrames;

void InitAnim(g2dTexture* tex, AnimFrames Frames, int animx, int animy, bool flipanim);
void PlayAnim(g2dTexture* tex, AnimFrames Frames[], int animx, int animy, int animcooldown, int lastframe, int backframe, bool flipanim);