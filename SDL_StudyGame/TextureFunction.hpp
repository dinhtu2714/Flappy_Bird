    
#ifndef TextureFunction_hpp
#define TextureFunction_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class TextureFunction
{
public:
    static SDL_Texture* Texture(const char* filelocation, SDL_Renderer* ren);
};

#endif /* TextureFunction_hpp */
