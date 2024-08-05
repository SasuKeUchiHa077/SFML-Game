#include "Header files/Game.h"

#define WIDTH 640
#define HEIGHT 480
//gu
int main (int argc, char *argv[]) {

    Game game;

    //Game loop
    while (game.Running()) {

        //update
        game.Update();

        //render
        game.Render();
    }
    return 0;
}
