#ifndef GameObject_hpp
#define GameObject_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "TextureFunction.hpp"
#include <iostream>
using namespace std;

class GameObject
{
private:
    SDL_Rect src, des;
    SDL_Texture* Tex;
public:
    GameObject();
    void setSrc(int x, int y, int w, int h);
    void setDes(int x, int y, int w, int h);
    void virtual Render(SDL_Renderer* ren) = 0;
    void CreateTexture(const char* address, SDL_Renderer* ren);
    SDL_Texture* getTexture();
    SDL_Rect& getSrc();
    SDL_Rect& getDes();
    SDL_Rect getDest();
};



#endif /* GameObject_hpp */
