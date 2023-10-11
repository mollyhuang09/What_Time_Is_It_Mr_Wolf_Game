#include "Game.hpp"
#include "Child.hpp"

#include <iostream>
#include <string>
using namespace std;


int main() {

    Game* new_game = new Game();

    string cmd;
    double x = 0;
    double y = 0;
    double t = 0;
    double D = 0;

    while (cin >> cmd){

        //when SPAWN command is called
        if (cmd == "SPAWN") {
            
            cin >> x;
            cin >> y;

            new_game->spawnNewChild(x,y);
        }
    
        //when TIME command is called
        else if (cmd == "TIME")
        {
            cin >> t;
            new_game->moveChildren(t);

        }

        //when NUM command is called
        else if (cmd == "NUM")
        {
            new_game->numOfChildren();

        }

        //when PRT command is called 
        else if (cmd == "PRT")
        {
            cin >> D;

            new_game->printChildren(D);
        }

        //when OVER command is called
        else if (cmd == "OVER")
        {
            new_game->over();
            
            delete new_game; 
        };
    }

    return 0;

}