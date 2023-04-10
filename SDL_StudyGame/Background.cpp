

#include "Background.hpp"

void Background::Render(SDL_Renderer* ren)
{
    SDL_RenderCopy(ren, getTexture(), NULL, NULL);
}
