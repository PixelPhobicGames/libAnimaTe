#include "AnimaTe/AnimaTe.hpp"

int main(){

    InitWindow(500 , 500 , "AnimaTe Example");

    SetTargetFPS(60);

    Animation Test = LoadAnimation("Animation/" , 8);


    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);

        DrawAnimationEx(Test , 50 ,50 , 2, Fast , 8 , WHITE);
        DrawAnimationEx(Test , 50 + 64,50 , 2, Normal , 8 , WHITE);
        DrawAnimationEx(Test , 50 + 128,50 , 2, Slow , 8 , WHITE);

        RunTickers();

        EndDrawing();
    }

    DeleteAnimation(Test , 8);
    
    CloseWindow();
}
