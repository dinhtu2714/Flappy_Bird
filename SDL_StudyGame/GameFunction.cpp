
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
    p[1].setDes(100, 218, 34, 24);
    p[2].setDes(100, 218, 34, 24);
    p[3].setDes(100, 218, 34, 24);
    p[4].setDes(100, 218, 34, 24);
    p1[1].setDes(128, 218, 34, 24);
    p1[2].setDes(128, 218, 34, 24);
    p1[3].setDes(128, 218, 34, 24);
    p1[4].setDes(128, 218, 34, 24);
    num_bird = 1;
    //button
    button_left.setDes(101, 222, 13, 16);
    button_right.setDes(175, 222, 13, 16);
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
    Menu_State= false;
    isFlash = true;
    GameOver = true;
    //
    newScore_des.x = 172;
    newScore_des.y = 230;
    newScore_des.w = 31;
    newScore_des.h = 13;
    newState = false;
    newscoreSound = true;
    MusicGameState = true;
    MusicMenuState = true;
    volumeState = true;
    //
    vol_button.x = 240;
    vol_button.y = 467;
    vol_button.w = 28;
    vol_button.h = 26;
    //
    medalDes.x = 50;
    medalDes.y = 212;
    medalDes.w = 50;
    medalDes.h = 50;
    //
    moveUp[1] = true;
    moveUp[2] = true;
    moveUp[3] = true;
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
            //set time
            now = time(0);
            ltm = localtime(&now);
            if (ltm->tm_hour >= 18 || ltm->tm_hour <= 5)
            {
                b.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/background-night.png", renderer);
                m1.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/menustart-night.png", renderer);
            }
            else
            {
                b.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/background-day.png", renderer);
                m1.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/menustart-day.png", renderer);
            }
            
            m.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/gameplay.png", renderer);
            m2.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/gameover_board.png", renderer);
            floor = TextureFunction::Texture("/Users/dinhtu/My Code/FlappyBirdGame/image/floor.png", renderer);
            newScore = TextureFunction::Texture("/Users/dinhtu/My Code/FlappyBirdGame/image/new.png", renderer);
            button_left.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/left.png", renderer);
            button_right.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/right.png", renderer);
            //
            pi1.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/pipe-green.png", renderer);
            pi2.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/pipe-green.png", renderer);
            pi3.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/pipe-green.png", renderer);
            //
            p[4].CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/greenbird1.png", renderer);
            p[4].CreateTexture1("/Users/dinhtu/My Code/FlappyBirdGame/image/greenbird2.png", renderer);
            p[4].CreateTexture2("/Users/dinhtu/My Code/FlappyBirdGame/image/greenbird3.png", renderer);
            p1[4].CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/greenbird1.png", renderer);
            p1[4].CreateTexture1("/Users/dinhtu/My Code/FlappyBirdGame/image/greenbird2.png", renderer);
            p1[4].CreateTexture2("/Users/dinhtu/My Code/FlappyBirdGame/image/greenbird3.png", renderer);
            //
            p[3].CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/bluebird1.png", renderer);
            p[3].CreateTexture1("/Users/dinhtu/My Code/FlappyBirdGame/image/bluebird2.png", renderer);
            p[3].CreateTexture2("/Users/dinhtu/My Code/FlappyBirdGame/image/bluebird3.png", renderer);
            p1[3].CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/bluebird1.png", renderer);
            p1[3].CreateTexture1("/Users/dinhtu/My Code/FlappyBirdGame/image/bluebird2.png", renderer);
            p1[3].CreateTexture2("/Users/dinhtu/My Code/FlappyBirdGame/image/bluebird3.png", renderer);
            //
            p[2].CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/redbird1.png", renderer);
            p[2].CreateTexture1("/Users/dinhtu/My Code/FlappyBirdGame/image/redbird2.png", renderer);
            p[2].CreateTexture2("/Users/dinhtu/My Code/FlappyBirdGame/image/redbird3.png", renderer);
            p1[2].CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/redbird1.png", renderer);
            p1[2].CreateTexture1("/Users/dinhtu/My Code/FlappyBirdGame/image/redbird2.png", renderer);
            p1[2].CreateTexture2("/Users/dinhtu/My Code/FlappyBirdGame/image/redbird3.png", renderer);
            //
            p[1].CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/yellowbird1.png", renderer);
            p[1].CreateTexture1("/Users/dinhtu/My Code/FlappyBirdGame/image/yellowbird2.png", renderer);
            p[1].CreateTexture2("/Users/dinhtu/My Code/FlappyBirdGame/image/yellowbird3.png", renderer);
            p1[1].CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/yellowbird1.png", renderer);
            p1[1].CreateTexture1("/Users/dinhtu/My Code/FlappyBirdGame/image/yellowbird2.png", renderer);
            p1[1].CreateTexture2("/Users/dinhtu/My Code/FlappyBirdGame/image/yellowbird3.png", renderer);
            //
            medal[1] = TextureFunction::Texture("/Users/dinhtu/My Code/FlappyBirdGame/image/bronze_medal.png", renderer);
            medal[2] = TextureFunction::Texture("/Users/dinhtu/My Code/FlappyBirdGame/image/silver_medal.png", renderer);
            medal[3] = TextureFunction::Texture("/Users/dinhtu/My Code/FlappyBirdGame/image/gold_medal.png", renderer);
            medal[4] = TextureFunction::Texture("/Users/dinhtu/My Code/FlappyBirdGame/image/platinum_medal.png", renderer);
            //
            flash = TextureFunction::Texture("/Users/dinhtu/My Code/FlappyBirdGame/image/white.png", renderer);
            //
            mute = TextureFunction::Texture("/Users/dinhtu/My Code/FlappyBirdGame/image/mute.png", renderer);
            unmute = TextureFunction::Texture("/Users/dinhtu/My Code/FlappyBirdGame/image/volume.png", renderer);
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
    
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
        cout<<"MIX init: "<<Mix_GetError()<<endl;
    else
    {
        sound_effect[0] = Mix_LoadWAV("/Users/dinhtu/My Code/FlappyBirdGame/sound/flap.wav");
        sound_effect[1] = Mix_LoadWAV("/Users/dinhtu/My Code/FlappyBirdGame/sound/point.wav");
        sound_effect[2] = Mix_LoadWAV("/Users/dinhtu/My Code/FlappyBirdGame/sound/hit.wav");
        sound_effect[3] = Mix_LoadWAV("/Users/dinhtu/My Code/FlappyBirdGame/sound/die.wav");
        sound_effect[4] = Mix_LoadWAV("/Users/dinhtu/My Code/FlappyBirdGame/sound/newScore.wav");
        sound_effect[5] = Mix_LoadWAV("/Users/dinhtu/My Code/FlappyBirdGame/sound/clicked.wav");
        sound_transition = Mix_LoadWAV("/Users/dinhtu/My Code/FlappyBirdGame/sound/swosh.wav");
        sound_menuGame = Mix_LoadWAV("/Users/dinhtu/My Code/FlappyBirdGame/sound/musicMenuStart.wav");
        sound_background = Mix_LoadMUS("/Users/dinhtu/My Code/FlappyBirdGame/sound/MusicinGame.mp3");
        
        if (sound_effect[0] == NULL || sound_effect[1] == NULL || sound_effect[2] == NULL || sound_effect[3] == NULL || sound_effect[5] == NULL || sound_transition == NULL || sound_background == NULL)
            cout << "LoadWAV Error " << endl;
        //set music volume
        Mix_VolumeMusic(80);
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
            temporary[1] = pi_y[1];
            max_des_y[1] = max(-290 , temporary[1] - 65);
        }
        movingPipe(1);
        pi1.setDes(pi_x[1], pi_y[1], 52, 320);
        pi_x[1] -=1;
        
        if (pi_x[2] <= -52)
        {
            pi_x[2] = pipe_x_reset;
            pi_y[2] = (-1) * uni(rng);
            temporary[2] = pi_y[2];
            max_des_y[2] = max(-290 , temporary[2] - 65);
        }
        if (score >= 21)
            movingPipe(2);
        pi2.setDes(pi_x[2], pi_y[2], 52, 320);
        pi_x[2] -=1;
        
        if (pi_x[3] <= -52)
        {
            pi_x[3] = pipe_x_reset;
            pi_y[3] = (-1) * uni(rng);
            temporary[3] = pi_y[3];
            max_des_y[3] = max(-290 , temporary[3] - 65);
        }
        movingPipe(3);
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
    if (Menu_State&& GameOver && (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN))
    {
        if (e.button.button == SDL_BUTTON_LEFT || e.key.keysym.sym == SDLK_SPACE)
        {
            Start = true;
            Mix_PlayChannel(-1, sound_effect[0], 0);
            p[num_bird].setJumpHeight(-3);
            p[num_bird].Jump();
        }
    }
    else
    {
        if (Start && GameOver && Menu_State)
        {
            p[num_bird].Gravity();
        }
    }
    
    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && !Start && !Menu_State)
    {
        if ((e.button.x >= 101 && e.button.x <= 101 + 13) && (e.button.y >= 222 && e.button.y <= 222 + 16))
        {
            Mix_PlayChannel(-1, sound_effect[5], 0);
            if (num_bird > 1)
                num_bird--;
            else
                num_bird = 4;
        }
        if ((e.button.x >= 175 && e.button.x <= 175 + 13) && (e.button.y >= 222 && e.button.y <= 222 + 16))
        {
            Mix_PlayChannel(-1, sound_effect[5], 0);
            if (num_bird < 4)
                num_bird++;
            else
                num_bird = 1;
        }
        if ((e.button.x >= 35 && e.button.x <= 35 + 99) && (e.button.y >= 321 && e.button.y <= 321 + 57))
        {
            Mix_PlayChannel(-1, sound_transition, 0);
            Menu_State= true;
        }
        if ((e.button.x >= 154 && e.button.x <= 154 + 99) && (e.button.y >= 321 && e.button.y <= 321 + 57) && !Menu_State)
        {
            GameState = false;
        }
        if ((e.button.x >= 240 && e.button.x <= 240 + 28) && (e.button.y >= 467 && e.button.y <= 467 + 26) && (!Menu_State))
        {
            if (volumeState)
            {
                Mix_Pause(1);
                volumeState = false;
                Mix_VolumeMusic(0);
                Mix_Volume(-1, 0);
            }
            else
            {
                volumeState = true;
                Mix_VolumeMusic(80);
                Mix_Volume(-1, 128);
                Mix_Resume(1);
                Mix_PlayChannel(-1, sound_effect[5], 0);
            }
        }
    }
    if ((CheckCollision::addScore(1) || CheckCollision::addScore(2) || CheckCollision::addScore(3)) && (GameOver))
    {
        Mix_PlayChannel(-1, sound_effect[1], 0);
        score++;
    }
}
void GameFunction::setDesForCheckCollison()
{
    GameFunction::pipe1 = pi1.getDest();
    GameFunction::pipe2 = pi2.getDest();
    GameFunction::pipe3 = pi3.getDest();
    GameFunction::player = p[num_bird].getDest();
}

void GameFunction::Render()
{
    SDL_RenderClear(renderer);
    
    now = time(0);
    ltm = localtime(&now);
    if (ltm->tm_hour >= 18 || ltm->tm_hour <= 5)
    {
        b.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/background-night.png", renderer);
        m1.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/menustart-night.png", renderer);
    }
    else
    {
        b.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/background-day.png", renderer);
        m1.CreateTexture("/Users/dinhtu/My Code/FlappyBirdGame/image/menustart-day.png", renderer);
    }
    
    b.Render(renderer);
    pi1.Render(renderer);
    pi2.Render(renderer);
    pi3.Render(renderer);
    if (Start && Menu_State)
    {
        if (GameOver)
            TextObject::Render(renderer, score);
        
    }
    else
        m.Render(renderer);
    if (GameOver)
    {
        p[num_bird].Render(renderer);
    }
    else
    {
        Mix_FadeOutMusic(1500);
        Flash();
        if (isFlash)
        {
            Mix_PlayChannel(-1, sound_effect[2], 0);
            //SDL_Delay(350);
            Mix_PlayChannel(-1, sound_effect[3], 0);
            isFlash = false;
        }
        SDL_RenderCopyEx(renderer, p[num_bird].getTexture(), NULL, &p[num_bird].getDes(), 90, NULL, SDL_FLIP_NONE);
        if (BirdFall())
            p[num_bird].Gravity();
        else
        {
            m2.Render(renderer);
            //medal
            if (score >= 40)
                SDL_RenderCopy(renderer, medal[4], NULL, &medalDes);
            else if (score >= 30)
            {
                SDL_RenderCopy(renderer, medal[3], NULL, &medalDes);
            }
            else if (score >= 20)
            {
                SDL_RenderCopy(renderer, medal[2], NULL, &medalDes);
            }
            else if (score >= 10)
            {
                SDL_RenderCopy(renderer, medal[1], NULL, &medalDes);
            }
            //highscore
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
            //renderScore
            TextObject::Render2(renderer, score, bestScore);
            if (newState)
            {
                if (newscoreSound)
                {
                    Mix_PlayChannel(-1, sound_effect[4], 0);
                    newscoreSound = false;
                }
                SDL_RenderCopy(renderer, newScore, NULL, &newScore_des);
            }
        }
        
    }
    if (!Menu_State)
    {
        
        m1.Render(renderer);
        p1[num_bird].Render(renderer);
        if (MusicMenuState)
        {
            Mix_PlayChannel(1, sound_menuGame, -1);
            MusicMenuState = false;
        }
        button_left.Render(renderer);
        button_right.Render(renderer);
    }
        SDL_RenderCopy(renderer, floor, NULL, &desFloor);
        SDL_RenderCopy(renderer, floor, NULL, &desFloor2);
    if (!Menu_State|| !GameOver)
    {
        if (volumeState)
        {
            SDL_RenderCopy(renderer, unmute, NULL, &vol_button);
        }
        else
        {
            SDL_RenderCopy(renderer, mute, NULL, &vol_button);
        }
    }

    SDL_RenderPresent(renderer);
    if (Menu_State&& MusicGameState)
    {
        Mix_FadeInMusic(sound_background, -1, 2000);
        Mix_HaltChannel(1);
        //Mix_PlayMusic(sound_background, -1);
        MusicGameState = false;
    }
}

void GameFunction::Clear()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    Mix_CloseAudio();
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
        SDL_Delay(70);
    }
    //isFlash = false;
}

void GameFunction::NewGame()
{
    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
    {
        SDL_Delay(200);
        if ((e.button.x >= 240 && e.button.x <= 240 + 28) && (e.button.y >= 467 && e.button.y <= 467 + 26) && (!GameOver))
        {
            if (volumeState)
            {
                volumeState = false;
                Mix_VolumeMusic(0);
                Mix_Volume(-1, 0);
            }
            else
            {
                volumeState = true;
                Mix_VolumeMusic(80);
                Mix_Volume(-1, 128);
                Mix_PlayChannel(-1, sound_effect[5], 0);
            }
        }
        if ((e.button.x >= 35 && e.button.x <= 35 + 99) && (e.button.y >= 321 && e.button.y <= 321 + 57) && !GameOver)
        {
            Mix_PlayChannel(-1, sound_transition, 0);
            p[num_bird].setDes(100, 218, 34, 24);
            p[num_bird].setYposDefault();
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
            Menu_State= true;
            isFlash = true;
            GameOver = true;
            newState = false;
            newscoreSound = true;
            MusicGameState = true;
            MusicMenuState = true;
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
            Mix_PlayChannel(-1, sound_transition, 0);
            //setPlayer
            
            p[num_bird].setDes(100, 218, 34, 24);
            p[num_bird].setYposDefault();
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
            Menu_State= false;
            isFlash = true;
            GameOver = true;
            newState = false;
            newscoreSound = true;
            MusicGameState = true;
            MusicMenuState = true;
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
    bird = p[num_bird].getDest();
    if (bird.y >= 407)
        return false;
    else
        return true;
}

bool GameFunction::getGameOver()
{
    return GameOver;
}

void GameFunction::movingPipe(int num)
{
    if (score >= 20)
    {
        if (pi_x[num] <= 288 && pi_x[num] >= -52 )
        {
            if (moveUp[num] && pi_y[num] > max_des_y[num])
            {
                pi_y[num] -= 1;
            }
            else
            {
                if (pi_y[num] < min(-10,max_des_y[num]+130))
                {
                    pi_y[num] += 1;
                    moveUp[num] = false;
                }
                else
                    moveUp[num] = true;
            }
        }
    }
}
