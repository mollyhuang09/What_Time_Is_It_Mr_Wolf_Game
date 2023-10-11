#include <iostream>
#include "Game.hpp"
#include "Child.hpp"

Child::Child (double x, double y) {
    x_coor = x;
    y_coor = y;
    next_child = nullptr;
}

Child::~Child() {
    x_coor = 0; 
    y_coor = 0;
    next_child = nullptr;
}

void Child::set_next(Child *new_next_child){
    next_child = new_next_child;
}

double Child::get_x_coor(){ return x_coor; }

double Child::get_y_coor(){ return y_coor; }

void Child::set_x_coor(double x) {x_coor = x;}

void Child::set_y_coor(double y) {y_coor = y;}

Child *Child::get_next() { return next_child; }