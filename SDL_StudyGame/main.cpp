#include "GameFunction.hpp"
GameFunction* g= new GameFunction();

int main(int argc, char* argv[])
{
    double first;
    double last = 0;
    g->Initialize();
    while (g->getGameState())
    {
        g->Event();
        g->Render();
        g->UpdateFloor();
        g->UpdatePipe();
        first = SDL_GetTicks();
        if (first - last <16.67)
        {
            SDL_Delay(16.67 - (first - last));
        }
        last = first;
    }
    g->Clear();
}
