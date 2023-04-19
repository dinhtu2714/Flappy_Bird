
#include "MenuGame.hpp"

void MenuGame::Render(SDL_Renderer* ren)
{
    SDL_RenderCopy(ren, getTexture(), NULL, &getDes());
}
