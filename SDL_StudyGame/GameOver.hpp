
#ifndef GameOver_hpp
#define GameOver_hpp

#include "GameObject.hpp"

class GameOver:public GameObject
{
private:
    SDL_Rect des;
public:
    GameOver();
    void Render(SDL_Renderer* ren);
};

#endif /* GameOver_hpp */
