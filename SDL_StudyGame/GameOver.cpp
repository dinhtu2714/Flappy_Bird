
#include "GameOver.hpp"
GameOver::GameOver()
{
    des.x = 144 - 96;
    des.y = 256 - 21;
    des.w = 192;
    des.h = 42;
}

void GameOver::Render(SDL_Renderer* ren)
{
    SDL_RenderCopy(ren, getTexture(), NULL, &des);
}
