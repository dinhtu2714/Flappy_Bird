
#ifndef GameFunction_hpp
#define GameFunction_hpp

#include "Player.hpp"
#include "Background.hpp"
#include "Pipe.hpp"
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
    bool GameState;
    bool Start = false;
    SDL_Event e;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Rect desFloor, desFloor2;
    SDL_Texture* floor;
    //int pi_x = 288;
    int pi_x[3];
public:
    GameFunction();
    bool getGameState();
    void Initialize();
    void Event();
    void Render();
    void Clear();
    void UpdateFloor();
    void UpdatePipe();
};


#endif /* GameFunction_hpp */
