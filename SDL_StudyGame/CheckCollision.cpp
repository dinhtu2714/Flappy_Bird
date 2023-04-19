
#include "CheckCollision.hpp"
bool CheckCollision::addState;
SDL_Rect CheckCollision::player;
SDL_Rect CheckCollision::score_rect;
int CheckCollision::Pipe_Blank = 110;

CheckCollision::CheckCollision()
{
    addState = false;
}

bool CheckCollision::check(int num)
{

    
    bird = GameFunction::getDesBird();
    bird.w = 34 + bird.x;
    bird.h = 24 + bird.y;
    if (bird.y <= 0 ||  bird.h >= 435)
        return true;
    
    top_pipe = GameFunction::getDesPi(num);
    top_pipe.h += top_pipe.y;
    top_pipe.y = 0;
    top_pipe.w = top_pipe.x + 52;
    
    
    bottom_pipe.x = top_pipe.x;
    bottom_pipe.y = top_pipe.h + Pipe_Blank;
    bottom_pipe.w = top_pipe.w;
    bottom_pipe.h = desFloor_y;
    
    //Check Top Pipe
    if (bird.x < top_pipe.w - 2 && top_pipe.x + 2 < bird.w)
    {
        if (bird.y < top_pipe.h - 2 && top_pipe.y + 2 < bird.h)
        {
            return true;
        }
    }
    
    //Check Bottom Pipe
    if (bottom_pipe.x + 2  < bird.w && bird.x < bottom_pipe.w - 2)
    {
        if (bottom_pipe.y + 2 < bird.h && bird.y < bottom_pipe.h - 2)
            return true;
    }
    if (bird.h >= 435)
        return true;
    //The last case
    return false;
}


bool CheckCollision::addScore(int num)
{
    addState = false;
    player = GameFunction::getDesBird();
    player.w = 34 + player.x;
    player.h = 24 + player.y;
    score_rect = GameFunction::getDesPi(num);
    score_rect.h += score_rect.y + Pipe_Blank;
    score_rect.y += 320;
    score_rect.w = score_rect.x + 52;
    
    
    if (player.w == score_rect.w && player.h < score_rect.h && player.h > score_rect.y)
    {
            addState = true;
    }
    return addState;
}

bool CheckCollision::runCheck()
{
    if (check(1) || check(2) || check(3))
        return true;
    return false;
}
