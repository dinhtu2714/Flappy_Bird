#include "GameObject.hpp"

GameObject::GameObject()
{
    Tex = NULL;
}
void GameObject::CreateTexture(const char* address, SDL_Renderer* ren)
{
    Tex = TextureFunction::Texture(address, ren);
    
}
SDL_Texture* GameObject::getTexture()
{
    return Tex;
}
SDL_Rect& GameObject::getSrc()
{
    return src;
}
SDL_Rect& GameObject::getDes()
{
    return des;
}
SDL_Rect& GameObject::getDes2()
{
    return des2;
}

void GameObject::setSrc(int x, int y , int w, int h)
{
    src.x = x;
    src.y = y;
    src.w = w;
    src.h = h;
}
void GameObject::setDes(int x, int y, int w, int h)
{
    des.x = x;
    des.y = y;
    des.w = w;
    des.h = h;
}
void GameObject::setDes2(int x, int y, int w, int h)
{
    des2.x = x;
    des2.y = y;
    des2.w = w;
    des2.h = h;
}
