
#ifndef GameFunction_hpp
#define GameFunction_hpp

#include "Player.hpp"
#include "Background.hpp"
#include "Pipe.hpp"
#include <random>
#include "CheckCollision.hpp"
#include "TextObject.hpp"

using namespace std;


class GameFunction {
private:
    Player p;
    Background b;
    Pipe pi1;
    Pipe pi2;
    Pipe pi3;
    const int SCREEN_W = 288;
    const int SCREEN_H = 512;
    bool GameState, GameOver = true;
    bool Start = false;
    bool isFlash = true;
    SDL_Event e;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Rect desFloor, desFloor2;
    SDL_Texture* floor;
    SDL_Texture* flash;
    //random des_pipes_y
    random_device rd;
    mt19937 rng{rd()};
    uniform_int_distribution<int> uni{1,290};
    
    int pipe_x_reset = 438;
    int pi_y[5];
    int pi_x[5];
    
    //Score
    int score = 0;
    
public:
    GameFunction();
    bool getGameState();
    static SDL_Rect getDesPi(int num);
    static SDL_Rect getDesBird();
    void Initialize();
    void Event();
    void Render();
    void Clear();
    void UpdateFloor();
    void UpdatePipe();
    void setDesForCheckCollison();
    static SDL_Rect pipe1,pipe2,pipe3,player;
    void setState(bool state);
    void Flash();
};


#endif /* GameFunction_hpp */
