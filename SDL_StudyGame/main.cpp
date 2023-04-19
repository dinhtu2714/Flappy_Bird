#include "CheckCollision.hpp"
#include "TextObject.hpp"

CheckCollision* c = new CheckCollision();
GameFunction* g = new GameFunction();


int main(int argc, char* argv[])
{
    double first;
    double last = 0;
    bool isGameOver = false;
    bool lastRen = true;
    bool isFlash = true;
    g->Initialize();
    while (g->getGameState())
    {
        g->Event();
        g->setDesForCheckCollison();
        if (!isGameOver && c->runCheck())
        {
            cout<<"Collided"<<endl;
            isGameOver = true;
            g->setState(false);
        }
        if (lastRen)
            g->Render();
        if (!isGameOver)
        {
            g->UpdateFloor();
            g->UpdatePipe();
        }
        else
        {
            if (isFlash)
            {
                SDL_Delay(100);
                isFlash = false;
            }
            g->RenderGameOver();
            lastRen = false;
        }
        
        //Limited 60FPS
        first = SDL_GetTicks();
        if (first - last <16.67)
        {
            SDL_Delay(16.67 - (first - last));
        }
        last = first;
    }
    g->Clear();
}
