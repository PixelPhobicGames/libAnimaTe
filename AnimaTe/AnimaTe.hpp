#include <raylib.h>
#include <iostream>

using namespace std;


// Easy and Tiny Animation Library for Raylib

// PixelPhobicGames 2023


#define Fast 3
#define Normal 2
#define Slow 1

#define MaxFrames 10


class Animation
{
    public:
        Texture2D AnimationFrames[MaxFrames];
        int FrameCount = 0;
        
};


class AnimaTe{
    public:
        int FastTicker = 0;
        int NormalTicker = 0;
        int SlowTicker = 0;

        int FastTickerSpeed = 3;
        int NormalTickerSpeed = 2;
        int SlowTickerSpeed = 1;
};

static AnimaTe AnimaTeCore;

void RunTickers(){
    AnimaTeCore.FastTicker += AnimaTeCore.FastTickerSpeed;
    AnimaTeCore.NormalTicker += AnimaTeCore.NormalTickerSpeed;
    AnimaTeCore.SlowTicker += AnimaTeCore.SlowTickerSpeed;

    if (AnimaTeCore.FastTicker >= 100){
        AnimaTeCore.FastTicker = 0;
    }
    if (AnimaTeCore.NormalTicker >= 100){
        AnimaTeCore.NormalTicker = 0;
    }
    if (AnimaTeCore.SlowTicker >= 100){
        AnimaTeCore.SlowTicker = 0;
    }
}
void SetTickerSpeed(int TickerType, int TicksPerSec){

    switch (TickerType)
    {
        case 3:
            AnimaTeCore.FastTickerSpeed = TicksPerSec;
            break;
    
        case 2:
            AnimaTeCore.FastTickerSpeed = TicksPerSec;
            break;

        case 1:
            AnimaTeCore.FastTickerSpeed = TicksPerSec;
            break;
        
        
        default:
            break;
    }

}

auto LoadAnimation(const char* Path , int Frames){
    Animation Out;

    for (int i = 0; i <= Frames - 1; i++){
        Out.AnimationFrames[i] = LoadTexture(FormatText("%sFrame%i.png" , Path , i));
    }

    return Out;
}

auto DrawAnimation(Animation CurrentAnimation , int X , int Y , int Speed, int Frames , Color Tint){
    int Ticker = 0;

    switch (Speed)
    {
        case 3:
            Ticker = AnimaTeCore.FastTicker;
            break;
        case 2:
            Ticker = AnimaTeCore.NormalTicker;
            break;
        case 1:
            Ticker = AnimaTeCore.SlowTicker;
            break;     
        default:
            break;
    }

    int CountFactor = 100 / (Frames-1);
    int Frame  = Ticker / CountFactor;

    DrawTexture(CurrentAnimation.AnimationFrames[Frame] , X , Y , Tint);

}

auto DrawAnimationEx(Animation CurrentAnimation , int X , int Y , float Scale , int Speed, int Frames , Color Tint){
    int Ticker = 0;

    switch (Speed)
    {
        case 3:
            Ticker = AnimaTeCore.FastTicker;
            break;
        case 2:
            Ticker = AnimaTeCore.NormalTicker;
            break;
        case 1:
            Ticker = AnimaTeCore.SlowTicker;
            break;     
        default:
            break;
    }

    int CountFactor = 100 / (Frames-1);
    int Frame  = Ticker / CountFactor;

    DrawTextureEx(CurrentAnimation.AnimationFrames[Frame] , { X , Y} , 0 , Scale , Tint);

}

void DeleteAnimation(Animation CurrentAnimation , int Frames){
    for (int i = 0; i <= Frames - 1; i++){
        UnloadTexture(CurrentAnimation.AnimationFrames[i]);
    }
}