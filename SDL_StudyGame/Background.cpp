

#include "Background.hpp"

void Background::Render(SDL_Renderer* ren)
{
    SDL_RenderCopy(ren, getTexture(), NULL, NULL);
}

void Background::Render1(SDL_Renderer* ren)
{
    SDL_RenderCopy(ren, getTexture(), NULL, &getDes2());
}
