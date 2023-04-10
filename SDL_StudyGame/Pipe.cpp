#include "Pipe.hpp"

void Pipe::Render(SDL_Renderer* ren)
{
    SDL_RenderCopyEx(ren, getTexture(), NULL, &getDes(), 0, NULL, SDL_FLIP_VERTICAL);
    //-------------
    dest = getDest();
    dest.y = dest.y + Pipe_Blank;
    SDL_RenderCopy(ren, getTexture(), NULL, &dest);
}
