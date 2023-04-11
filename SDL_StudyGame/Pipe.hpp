
#ifndef Pipe_hpp
#define Pipe_hpp

#include "GameObject.hpp"

class Pipe:public GameObject
{
private:
    SDL_Rect dest;
    int Pipe_Blank = 430;
public:
    void Render (SDL_Renderer* ren);
};

#endif /* Pipe_hpp */
