#include "headerFiles/Game.h"
#include <cstddef>
#include <cstdlib>
#include <ctime>

#define WIDTH 640
#define HEIGHT 480

int main (int argc, char *argv[]) {

    //Init random
    std::srand(static_cast<unsigned int>(time(NULL)));

    //Game object
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
