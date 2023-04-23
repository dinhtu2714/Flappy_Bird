
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
    //p.setSrc(0, 0, 34, 24);
    p.setDes(100, 218, 34, 24);
    p1.setDes(128, 218, 34, 24);
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
    m1.setDes(0, 0, 288, 512);
    m2.setDes(0, 0, 288, 512);
    //
    Start = false;
    Start1 = false;
    isFlash = true;
    GameOver = true;
    //
    newScore_des.x = 172;
    newScore_des.y = 230;
    newScore_des.w = 31;
    newScore_des.h = 13;
    newState = false;
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
            m.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/gameplay.png", renderer);
            m1.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/menustart.png", renderer);
            m2.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/gameover_board.png", renderer);
            floor = TextureFunction::Texture("/Users/dinhtu/My Code/FlappyBirdGame/image/floor.png", renderer);
            newScore = TextureFunction::Texture("/Users/dinhtu/My Code/FlappyBirdGame/image/new.png", renderer);
            //
            pi1.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/pipe-green.png", renderer);
            pi2.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/pipe-green.png", renderer);
            pi3.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/pipe-green.png", renderer);
            //
            p.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/yellowbird1.png", renderer);
            p.CreateTexture1("/Users/dinhtu/My Code/FlappyBirdGame/image/yellowbird2.png", renderer);
            p.CreateTexture2("/Users/dinhtu/My Code/FlappyBirdGame/image/yellowbird3.png", renderer);
            p1.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/yellowbird1.png", renderer);
            p1.CreateTexture1("/Users/dinhtu/My Code/FlappyBirdGame/image/yellowbird2.png", renderer);
            p1.CreateTexture2("/Users/dinhtu/My Code/FlappyBirdGame/image/yellowbird3.png", renderer);
            flash = TextureFunction::Texture("/Users/dinhtu/My Code/FlappyBirdGame/image/white.png", renderer);
        }
    }
    if (TTF_Init() < 0)
        cout<<"TTF init: "<<TTF_GetError()<<endl;
    ifstream file("/Users/dinhtu/My Code/FlappyBirdGame/data/BestScore.txt");
    if (!file.is_open())
        {
            cout << "Unable to open bestscore file!" << endl;
        }
    else
    {
        file >> bestScore;
        file.close();
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
    if (Start1 && GameOver && (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN))
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
        if (Start && GameOver && Start1)
        {
            p.Gravity();
        }
    }
    
    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && !Start && !Start1)
    {
        if ((e.button.x >= 35 && e.button.x <= 35 + 99) && (e.button.y >= 321 && e.button.y <= 321 + 57))
        {
            Start1 = true;
        }
        if ((e.button.x >= 154 && e.button.x <= 154 + 99) && (e.button.y >= 321 && e.button.y <= 321 + 57) && !Start1)
            GameState = false;
    }
    if ((CheckCollision::addScore(1) || CheckCollision::addScore(2) || CheckCollision::addScore(3)) && (GameOver))
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
    if (Start && Start1)
    {
        if (GameOver)
            TextObject::Render(renderer, score);
    }
    else
        m.Render(renderer);
    if (GameOver)
    {
        p.Render(renderer);
    }
    else
    {
        SDL_RenderCopyEx(renderer, p.getTexture(), NULL, &p.getDes(), 90, NULL, SDL_FLIP_NONE);
        Flash();
        if (BirdFall())
            p.Gravity();
        m2.Render(renderer);
        if (score > bestScore)
        {
            newState = true;
            bestScore = score;
            ofstream file("/Users/dinhtu/My Code/FlappyBirdGame/data/BestScore.txt");
            if (!file.is_open())
                {
                    cout << "Unable to open bestscore file!" << endl;
                }
            else
            {
                file << bestScore;
                file.close();
            }
        }
        TextObject::Render2(renderer, score, bestScore);
        if (newState)
            SDL_RenderCopy(renderer, newScore, NULL, &newScore_des);
    }
    if (!Start1)
    {
        
        m1.Render(renderer);
        p1.Render(renderer);
    }
    SDL_RenderCopy(renderer, floor, NULL, &desFloor);
    SDL_RenderCopy(renderer, floor, NULL, &desFloor2);
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
    isFlash = false;
}

void GameFunction::NewGame()
{
    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
    {
        SDL_Delay(200);
        if ((e.button.x >= 35 && e.button.x <= 35 + 99) && (e.button.y >= 321 && e.button.y <= 321 + 57) && !GameOver)
        {
            
            p.setDes(100, 218, 34, 24);
            p.setYposDefault();
            //setPi_x
            pi_x[1] = 360;
            pi_x[2] = 530;
            pi_x[3] = 690;
            //setPi_y
            pi_y[1] = -uni(rng);
            pi_y[2] = -uni(rng);
            pi_y[3] = -uni(rng);
            
            pi1.setDes(pi_x[1], pi_y[1], 52, 320);
            pi2.setDes(pi_x[1], pi_y[1], 52, 320);
            pi3.setDes(pi_x[1], pi_y[1], 52, 320);
            
            setDesForCheckCollison();
            //setScore
            score = 0;
            //
            Start = false;
            Start1 = true;
            isFlash = true;
            GameOver = true;
            newState = false;
            //
            ifstream file("/Users/dinhtu/My Code/FlappyBirdGame/data/BestScore.txt");
            if (!file.is_open())
                {
                    cout << "Unable to open bestscore file!" << endl;
                }
            else
            {
                file >> bestScore;
                file.close();
            }
        }
        if ((e.button.x >= 154 && e.button.x <= 154 + 99) && (e.button.y >= 321 && e.button.y <= 321 + 57) && !GameOver)
        {

            //setPlayer
            
            p.setDes(100, 218, 34, 24);
            p.setYposDefault();
            //setPi_x
            pi_x[1] = 360;
            pi_x[2] = 530;
            pi_x[3] = 690;
            //setPi_y
            pi_y[1] = -uni(rng);
            pi_y[2] = -uni(rng);
            pi_y[3] = -uni(rng);
            
            pi1.setDes(pi_x[1], pi_y[1], 52, 320);
            pi2.setDes(pi_x[1], pi_y[1], 52, 320);
            pi3.setDes(pi_x[1], pi_y[1], 52, 320);
            
            setDesForCheckCollison();
            //setScore
            score = 0;
            //
            Start = false;
            Start1 = false;
            isFlash = true;
            GameOver = true;
            newState = false;
            //
            ifstream file("/Users/dinhtu/My Code/FlappyBirdGame/data/BestScore.txt");
            if (!file.is_open())
                {
                    cout << "Unable to open bestscore file!" << endl;
                }
            else
            {
                file >> bestScore;
                file.close();
            }
        }
    }

}

bool GameFunction::BirdFall()
{
    bird = p.getDest();
    if (bird.y >= 407)
        return false;
    else
        return true;
}

bool GameFunction::getGameOver()
{
    return GameOver;
}
