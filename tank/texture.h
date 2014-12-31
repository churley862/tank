//
//  texture.h
//  tank
//
//  Created by Kitchen on 12/31/14.
//  Copyright (c) 2014 Collin. All rights reserved.
//

#ifndef __tank__texture__
#define __tank__texture__

#include<string>
#include <map>
#include "world.hpp"

class Texture
{
private:
    static std::map<std::string, SDL_Texture*> textures;

public:
    static SDL_Texture* getTexture(const std::string& fname)
    {
        auto value = textures.find(fname);

        if (value == textures.end())
        {
            SDL_Texture* t = World::getWorld().loadTexture(fname.c_str());
            textures[fname] = t;
            return t;
        }

        return value->second;
    }
};


#endif /* defined(__tank__texture__) */
