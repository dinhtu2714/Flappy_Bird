
#include "GameFunction.hpp"

GameFunction::GameFunction()
{
    window = NULL;
    renderer = NULL;
    GameState = false;
    //setdesFloor
    desFloor.x = 0;
    desFloor.y = 435;
    desFloor.w = 336;
    desFloor.h = 112;
    //setdesFloor2
    desFloor2.x = 336;
    desFloor2.y = 435;
    desFloor2.w = 336;
    desFloor2.h = 112;
    //setPlayer
    p.setSrc(0, 0, 34, 24);
    p.setDes(100,256, 34, 24);
    //setPi_x
    pi_x[1] = 288;
    pi_x[2] = 457;
    pi_x[3] = 636;
}
bool GameFunction::getGameState()
{
    return GameState;
}
void GameFunction::Initialize()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        cout << "Window: " << &SDL_GetError << endl;
    }
    else
    {
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer == NULL)
        {
            cout << "Renderer: " << &SDL_GetError << endl;
        }
        else
        {
            GameState = true;
            cout << "Successed";
            b.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/background.png", renderer);
            floor = TextureFunction::Texture("/Users/dinhtu/My Code/FlappyBirdGame/image/floor.png", renderer);
            pi1.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/pipe-green.png", renderer);
            pi2.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/pipe-green.png", renderer);
            pi3.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/pipe-green.png", renderer);
            p.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/yellowbird1.png", renderer);
            p.CreateTexture1("/Users/dinhtu/My Code/FlappyBirdGame/image/yellowbird2.png", renderer);
            p.CreateTexture2("/Users/dinhtu/My Code/FlappyBirdGame/image/yellowbird3.png", renderer);
        }
    }
}
void GameFunction::UpdateFloor()
{
    if (desFloor.x <= -336)
        desFloor.x = 336;
    if (desFloor2.x <=-336)
        desFloor2.x = 336;
    desFloor.x -= 1;
    desFloor2.x -=1;
    
}

void GameFunction::UpdatePipe()
{
    if (Start)
    {
        if (pi_x[1] <=-52)
            pi_x[1] = 465;
        pi1.setDes(pi_x[1], -130, 52, 320);
        pi1.setDes2(pi_x[1], 295, 52, 320);
        pi_x[1] -=1;
        
        if (pi_x[2] <= -52)
            pi_x[2] = 465;
        pi2.setDes(pi_x[2], -45, 52, 320);
        pi2.setDes2(pi_x[2], 380, 52, 320);
        pi_x[2] -=1;
        
        if (pi_x[3] <= -52)
            pi_x[3] = 465;
        pi3.setDes(pi_x[3], -200, 52, 320);
        pi3.setDes2(pi_x[3], 225, 52, 320);
        pi_x[3] -=1;
    }
}

void GameFunction::Event()
{
    SDL_PollEvent(&e);
    if (e.type == SDL_QUIT)
    {
        GameState = false;
    }
    if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
    {
        if (e.key.keysym.sym == SDLK_UP || e.button.button == SDL_BUTTON_LEFT)
        {
            Start = true;
            p.setJumpHeight();
            p.Jump();
        }
    }
    else
    {
        if (Start)
        {
            p.Gravity();
        }
    }
}

void GameFunction::Render()
{
    SDL_RenderClear(renderer);
    b.Render(renderer);
    pi1.Render(renderer);
    pi1.Render1(renderer);
    pi2.Render(renderer);
    pi2.Render1(renderer);
    pi3.Render(renderer);
    pi3.Render1(renderer);
    SDL_RenderCopy(renderer, floor, NULL, &desFloor);
    SDL_RenderCopy(renderer, floor, NULL, &desFloor2);
    p.Render(renderer);
    SDL_RenderPresent(renderer);
}

void GameFunction::Clear()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
