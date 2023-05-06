
#ifndef GameFunction_hpp
#define GameFunction_hpp

#include "Player.hpp"
#include "Background.hpp"
#include "Pipe.hpp"
#include <random>
#include "CheckCollision.hpp"
#include "TextObject.hpp"
#include "MenuGame.hpp"
#include <fstream>
#include <SDL2_mixer/SDL_mixer.h>

using namespace std;
    

class GameFunction {
private:
    Player p[4];  //ingame
    Player p1[4]; //inmenu
    Background b;
    Pipe pi1;
    Pipe pi2;
    Pipe pi3;
    MenuGame m;  //GamePlay
    MenuGame m1; //MenuStart
    MenuGame m2; //GameOver_Board
    MenuGame button_left;
    MenuGame button_right;
    const int SCREEN_W = 288;
    const int SCREEN_H = 512;
    bool GameState, GameOver;
    bool Start;  //play
    bool Start1; //menu
    bool isFlash;
    bool newscoreSound;
    bool MusicGameState;
    bool MusicMenuState;
    bool volumeState ;
    SDL_Event e;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Rect desFloor, desFloor2;
    SDL_Rect bird,newScore_des;
    SDL_Rect vol_button;
    SDL_Rect medalDes;
    SDL_Texture* floor;
    SDL_Texture* flash;
    SDL_Texture* newScore;
    SDL_Texture* mute;
    SDL_Texture* unmute;
    //SDL_Texture* button;
    //random des_pipes_y
    random_device rd;
    mt19937 rng{rd()};
    uniform_int_distribution<int> uni{1,290};
    
    int pipe_x_reset = 438;
    int pi_y[5];
    int pi_x[5];
    
    //Score
    int score,bestScore;
    bool newState;
    //
    Mix_Chunk* sound_effect[6];
    Mix_Chunk* sound_transition;
    Mix_Chunk* sound_menuGame;
    Mix_Music* sound_background;
    //
    int num_bird;
public:
    GameFunction();
    bool getGameState();
    static SDL_Rect getDesPi(int num);
    static SDL_Rect getDesBird();
    void Initialize();
    void Event();
    void Render();
    void NewGame();
    void Clear();
    void UpdateFloor();
    void UpdatePipe();
    void setDesForCheckCollison();
    static SDL_Rect pipe1,pipe2,pipe3,player;
    void setState(bool state);
    void Flash();
    bool BirdFall();
    bool getGameOver();
};


#endif /* GameFunction_hpp */
