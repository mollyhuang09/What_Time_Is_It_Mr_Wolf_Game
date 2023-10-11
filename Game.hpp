#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>

#include "Child.hpp"

class Game {
public:
    //Contructor
    Game(); 

    //Destructor 
    ~Game();

    //spawning a new child
    void spawnNewChild(double x, double y); 

    //remove child 
    void removeChild(double x, double y);

    //moving the children depending on the time given by user
    void moveChildren(double t);

    //number of children still playing 
    void numOfChildren();

    //printing the children that are less than distance D away from the wolf 
    void printChildren(double D);

    void over(); 

    Child *get_head_child();

private: 
    Child *head_child;
};

#endif