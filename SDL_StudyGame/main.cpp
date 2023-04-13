#include "CheckCollision.hpp"
#include "TextObject.hpp"

CheckCollision* c = new CheckCollision();
GameFunction* g = new GameFunction();
TextObject* t = new TextObject();


int main(int argc, char* argv[])
{
    double first;
    double last = 0;
    g->Initialize();
    bool isGameOver = false;
    while (g->getGameState())
    {
        g->Event();
        g->setDesForCheckCollison();
        if (!isGameOver && (c->check(1) || c->check(2) || c->check(3)))
        {
            cout<<"Collided"<<endl;
            isGameOver = true;
            g->setState(false);
        }
        g->Render();
        if (!isGameOver)
        {
            g->UpdateFloor();
            g->UpdatePipe();
        }
        
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
