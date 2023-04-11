
#include "TextureFunction.hpp"

SDL_Texture* TextureFunction::Texture(const char* filelocation, SDL_Renderer* ren)
{
    SDL_Texture* tex = NULL;
    tex = IMG_LoadTexture(ren, filelocation);
    return tex;
}
