
#include "GameFunction.hpp"

SDL_Rect GameFunction::pipe1 ;
SDL_Rect GameFunction::pipe2 ;
SDL_Rect GameFunction::pipe3 ;
SDL_Rect GameFunction::player ;


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
    pi_x[1] = 360;
    pi_x[2] = 530;
    pi_x[3] = 690;
    //setPi_y
    pi_y[1] = -uni(rng);
    pi_y[2] = -uni(rng);
    pi_y[3] = -uni(rng);
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
            cout << "Successed" <<endl;
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
        {
            pi_x[1] = pipe_x_reset;
            pi_y[1] = (-1) * uni(rng);
        }
        pi1.setDes(pi_x[1], pi_y[1], 52, 320);
        pi_x[1] -=1;
        
        if (pi_x[2] <= -52)
        {
            pi_x[2] = pipe_x_reset;
            pi_y[2] = (-1) * uni(rng);
        }
        pi2.setDes(pi_x[2], pi_y[2], 52, 320);
        pi_x[2] -=1;
        
        if (pi_x[3] <= -52)
        {
            pi_x[3] = pipe_x_reset;
            pi_y[3] = (-1) * uni(rng);
        }
        pi3.setDes(pi_x[3], pi_y[3], 52, 320);
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
void GameFunction::setDesForCheckCollison()
{
    GameFunction::pipe1 = pi1.getDest();
    GameFunction::pipe2 = pi2.getDest();
    GameFunction::pipe3 = pi3.getDest();
    GameFunction::player = p.getDest();
}

void GameFunction::Render()
{
    SDL_RenderClear(renderer);
    b.Render(renderer);
    pi1.Render(renderer);
    pi2.Render(renderer);
    pi3.Render(renderer);
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

SDL_Rect GameFunction::getDesPi(int num)
{
    if (num == 1)
        return pipe1;
    if (num == 2)
        return pipe2;
    else
    return pipe3;
}
SDL_Rect GameFunction::getDesBird()
{
    return player;
}
