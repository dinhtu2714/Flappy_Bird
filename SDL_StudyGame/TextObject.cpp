
#include "TextObject.hpp"
TTF_Font* TextObject::font;
SDL_Surface* TextObject::surface;
SDL_Rect TextObject::src;
SDL_Rect TextObject::des;
SDL_Texture* TextObject::texture;
SDL_Color TextObject::color;
string TextObject::s;


void TextObject::Render(SDL_Renderer* ren, int score)
{
    color = {255,255,255};
    s = to_string(score);
    font = TTF_OpenFont("/Users/dinhtu/My Code/FlappyBirdGame/font/flappy-font.ttf", 24);
    surface = TTF_RenderText_Solid(font, s.c_str(), color);
    texture = SDL_CreateTextureFromSurface(ren, surface);
    TTF_SizeText(font, s.c_str(), &src.w, &src.h);
    des.x = 140;
    des.y = 20;
    des.w = src.w ;
    des.h = src.h ;
    src.x = 0;
    src.y = 0;
    SDL_RenderCopy(ren, texture, &src, &des);
}