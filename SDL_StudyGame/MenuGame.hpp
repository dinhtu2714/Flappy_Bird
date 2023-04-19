
#ifndef MenuGame_hpp
#define MenuGame_hpp

#include "GameObject.hpp"

class MenuGame: public GameObject
{
public:
    void Render(SDL_Renderer* ren);
};

#endif /* MenuGame_hpp */
