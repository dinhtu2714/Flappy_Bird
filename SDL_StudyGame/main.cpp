#include "GameFunction.hpp"
#include "CheckCollision.hpp"

CheckCollision* c = new CheckCollision();
GameFunction* g = new GameFunction();



int main(int argc, char* argv[])
{
    double first;
    double last = 0;
    g->Initialize();
    while (g->getGameState())
    {
        
        g->Event();
        g->setDesForCheckCollison();
        if (c->check(1) || c->check(2) || c->check(3))
        {
            cout<<"Va Cham"<<endl;
            break;
        }
        g->Render();
        g->UpdateFloor();
        g->UpdatePipe();
        
        //Limiting FPS
        first = SDL_GetTicks();
        if (first - last <16.67)
        {
            SDL_Delay(16.67 - (first - last));
        }
        last = first;
    }
    g->Clear();
}
