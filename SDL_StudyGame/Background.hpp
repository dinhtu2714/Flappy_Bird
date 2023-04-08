
#ifndef Background_hpp
#define Background_hpp

#include "GameObject.hpp"

class Background:public GameObject
{
private:
public:
    void Render(SDL_Renderer* ren);
    void Render1(SDL_Renderer* ren);
};



#endif /* Background_hpp */
