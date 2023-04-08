
#ifndef Pipe_hpp
#define Pipe_hpp

#include "GameObject.hpp"

class Pipe:public GameObject
{
private:
public:
    void Render (SDL_Renderer* ren);
    void Render1 (SDL_Renderer* ren);
};

#endif /* Pipe_hpp */
