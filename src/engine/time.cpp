#include "time.h"

Time::Time() : frameStart(0), lastFrame(0), frameTime(0)
{
}

Time::~Time()
{
}

int Time::computeDeltaTime()
{
    frameStart = SDL_GetTicks();
    int dt = frameStart - lastFrame;
    lastFrame = frameStart;
    return dt;
}

void Time::delayTime()
{
    frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < frameDelay) {
        SDL_Delay(frameDelay - frameTime);
    }
}