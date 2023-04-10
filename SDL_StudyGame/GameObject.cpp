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
SDL_Rect GameObject::getDest()
{
    return des;
}
//-------------------------Set
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
