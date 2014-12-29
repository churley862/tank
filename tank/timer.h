//
//  timer.h
//  tank
//
//  Created by Kitchen on 12/27/14.
//  Copyright (c) 2014 Collin. All rights reserved.
//

#ifndef __tank__timer__
#define __tank__timer__

#include <stdio.h>
#include "sdl.h"
class Timer {
public:
    Timer(){reset();}
    void reset(){startTime = SDL_GetTicks();}
    int getTime (){return SDL_GetTicks()- startTime;}
void waitFor (int ms)
    {
        int delay=(ms-getTime());
        if (delay > 0)
            SDL_Delay(delay);
    
    }
    

private :
    Uint32 startTime;

};
#endif /* defined(__tank__timer__) */
