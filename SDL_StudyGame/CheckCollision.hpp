
#ifndef CheckCollision_hpp
#define CheckCollision_hpp

#include "GameFunction.hpp"

class CheckCollision
{
private:
    SDL_Rect bird, top_pipe, bottom_pipe;
    int Pipe_Blank = 110, desFloor_y = 435;
public:
    CheckCollision();
    bool check(int num);
};

#endif /* CheckCollision_hpp */
