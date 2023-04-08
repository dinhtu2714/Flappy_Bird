#ifndef Player_hpp
#define Player_hpp

#include "GameObject.hpp"

class Player:public GameObject
{
private:
    double gravity = 0.12;
    int Ypos = 256;
    double jumpHeight = 0;
    SDL_Texture* Tex1;
    SDL_Texture* Tex2;
    int animationTimer;
public:
    void setJumpHeight();
    void Gravity();
    void Jump();
    void Render(SDL_Renderer* ren);
    void Render1(SDL_Renderer* ren);
    void CreateTexture1(const char* address, SDL_Renderer* ren);
    void CreateTexture2(const char* address, SDL_Renderer* ren);
};





#endif /* Player_hpp */
