
#ifndef CheckCollision_hpp
#define CheckCollision_hpp

#include "GameFunction.hpp"

class CheckCollision
{
private:
    SDL_Rect bird, top_pipe, bottom_pipe;
    static int Pipe_Blank;
    int desFloor_y = 435;
    static bool addState;
    static SDL_Rect player, score_rect;
public:
    CheckCollision();
    bool check(int num);
    static bool addScore(int num);
};

#endif /* CheckCollision_hpp */
