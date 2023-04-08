#include "Pipe.hpp"

void Pipe::Render(SDL_Renderer* ren)
{
    SDL_RenderCopyEx(ren, getTexture(), NULL, &getDes(), 0, NULL, SDL_FLIP_VERTICAL);
}

void Pipe::Render1(SDL_Renderer* ren)
{
    SDL_RenderCopy(ren, getTexture(), NULL, &getDes2());
}
