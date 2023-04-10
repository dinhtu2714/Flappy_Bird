#include "Player.hpp"

void Player::Render(SDL_Renderer* ren)
{
    animationTimer++;
    if (animationTimer < 16)
    {
        SDL_RenderCopy(ren, getTexture(), NULL, &getDes());
    }
    else if (animationTimer >= 16 && animationTimer <= 32)
    {
        SDL_RenderCopy(ren, Tex1, NULL, &getDes());
    }
    else if (animationTimer > 32)
    {
        SDL_RenderCopy(ren, Tex2, NULL, &getDes());
    }
    if (animationTimer > 48)
    {
        animationTimer = 0;
    }
}

void Player::Gravity()
{
    jumpHeight += gravity;
    Ypos += jumpHeight;
    setDes(100, Ypos, 34, 24);
}

void Player::setJumpHeight()
{
    jumpHeight = -3;
}

void Player::Jump()
{
    jumpHeight += gravity;
    Ypos += jumpHeight;
    setDes(100, Ypos, 34, 24);
}

void Player::CreateTexture1(const char* address, SDL_Renderer* ren)
{
    Tex1 = TextureFunction::Texture(address, ren);
}

void Player::CreateTexture2(const char* address, SDL_Renderer* ren)
{
    Tex2 = TextureFunction::Texture(address, ren);
}
