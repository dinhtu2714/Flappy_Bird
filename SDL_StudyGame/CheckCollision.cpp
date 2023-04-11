
#include "CheckCollision.hpp"

CheckCollision::CheckCollision()
{
}

bool CheckCollision::check(int num)
{
    bird = GameFunction::getDesBird();
    if (bird.y <= 0)
        return true;
    
    bird.w = 34 + bird.x;
    bird.h = 24 + bird.y;
    
    top_pipe = GameFunction::getDesPi(num);
    top_pipe.h += top_pipe.y;
    top_pipe.y = 0;
    top_pipe.w = top_pipe.x + 52;
    
    
    bottom_pipe.x = top_pipe.x;
    bottom_pipe.y = top_pipe.h + Pipe_Blank;
    bottom_pipe.w = top_pipe.w;
    bottom_pipe.h = desFloor_y;
    
    //Check Top Pipe
    if (bird.x <= top_pipe.w && top_pipe.x <= bird.w)
    {
        if (bird.y <= top_pipe.h && top_pipe.y <= bird.h)
        {
            return true;
        }
    }
    
    //Check Bottom Pipe
    if (bottom_pipe.x <= bird.w && bird.x <= bottom_pipe.w)
    {
        if (bottom_pipe.y <= bird.h && bird.y <= bottom_pipe.h)
            return true;
    }
    if (bird.h >= 435)
        return true;
    
    return false;
}
