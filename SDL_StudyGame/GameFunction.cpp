
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
    //setScore
    score = 0;
    //
    m.setDes(0, 0, 288, 512);
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
            m.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/gameplay_image.png", renderer);
            g.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/gameover.png", renderer);
            floor = TextureFunction::Texture("/Users/dinhtu/My Code/FlappyBirdGame/image/floor.png", renderer);
            pi1.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/pipe-green.png", renderer);
            pi2.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/pipe-green.png", renderer);
            pi3.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/pipe-green.png", renderer);
            p.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/yellowbird1.png", renderer);
            p.CreateTexture1("/Users/dinhtu/My Code/FlappyBirdGame/image/yellowbird2.png", renderer);
            p.CreateTexture2("/Users/dinhtu/My Code/FlappyBirdGame/image/yellowbird3.png", renderer);
            flash = TextureFunction::Texture("/Users/dinhtu/My Code/FlappyBirdGame/image/white.png", renderer);
        }
    }
    if (TTF_Init() < 0)
        cout<<"TTF init: "<<TTF_GetError()<<endl;
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
    if (GameOver && (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN))
    {
        if (e.button.button == SDL_BUTTON_LEFT || e.key.keysym.sym == SDLK_SPACE)
        {
            Start = true;
            p.setJumpHeight(-3);
            p.Jump();
        }
    }
    else
    {
        if (Start && GameOver)
        {
            p.Gravity();
        }
    }
    if (CheckCollision::addScore(1) || CheckCollision::addScore(2) || CheckCollision::addScore(3))
        score++;
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
    if (Start)
        TextObject::Render(renderer, score);
    else
        m.Render(renderer);
    if (GameOver)
    {
        p.Render(renderer);
    }
    else
    {
        SDL_RenderCopy(renderer, p.getTexture(), NULL, &p.getDes());
        Flash();
    }
    SDL_RenderPresent(renderer);
}

void GameFunction::Clear()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
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

void GameFunction::setState(bool state)
{
    GameOver = state;
}
void GameFunction::Flash()
{
    if (isFlash)
    {
        SDL_RenderCopy(renderer, flash, NULL, NULL);
    }
    SDL_Delay(50);
    isFlash = false;
}

void GameFunction::RenderGameOver()
{
    SDL_RenderClear(renderer);
    b.Render(renderer);
    g.Render(renderer);
    SDL_RenderPresent(renderer);
}
