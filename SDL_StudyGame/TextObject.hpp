 
#ifndef TextObject_hpp
#define TextObject_hpp

#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include "GameObject.hpp"

using namespace std;

class TextObject
{
private:
    static TTF_Font* font;
    static SDL_Surface* surface;
    static SDL_Texture* texture;
    static SDL_Rect des,src;
    static SDL_Color color;
    static string s;
public:
    static void Render(SDL_Renderer* ren, int score);
    static void Render2(SDL_Renderer* ren, int score);
    static void Render3(SDL_Renderer* ren, int score);
};



#endif /* TextObject_hpp */
