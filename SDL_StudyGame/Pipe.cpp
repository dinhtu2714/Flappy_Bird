#include "Pipe.hpp"

void Pipe::Render(SDL_Renderer* ren)
{
    //----Top Pipe
    SDL_RenderCopyEx(ren, getTexture(), NULL, &getDes(), 0, NULL, SDL_FLIP_VERTICAL);
    //----Bottom Pipe
    dest = getDest();
    dest.y = dest.y + Pipe_Blank;
    SDL_RenderCopy(ren, getTexture(), NULL, &dest);
}
