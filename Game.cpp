#include "Game.hpp"
#include "Child.hpp"

#include <iostream>
#include <cmath>

//constructor
Game::Game() { 
    head_child = 0;
}

//decontructor
Game::~Game(){
    Child *current_child = head_child; 

    while (head_child != nullptr){
        head_child = head_child->get_next();
        delete current_child;
        current_child = nullptr;
        current_child = head_child; 
    }
}

//inserting new child into the linked list
void Game::spawnNewChild(double x, double y){   
    Child *current_child = head_child; 
    
    //if child is in the first quadrant -> insert child
    if (x>0 && y>0){
        Child* new_child = new Child (x,y);
        if (head_child == nullptr){ //if the head node is empty -> put new child as head
            head_child = new_child;
        }else{ 
            current_child = head_child; 

            while (current_child->get_next() != nullptr){
                current_child = current_child->get_next();
            }

            current_child->set_next(new_child);
        }

        std::cout << "success" << std::endl;   
     
    }else { //child is not in the first quadrant
        std::cout << "failure" << std::endl;
    }
}

//removing child from linked list

void Game::removeChild(double x, double y){
    Child *current_child = head_child->get_next(); 
    Child *prev_child = head_child;

    if (head_child == nullptr) {
        return ; 
    }

   //if head child needs to be removed 
    if (head_child->get_x_coor() == x && head_child->get_y_coor() == y){
        Child* temp = head_child; 
        head_child = head_child->get_next();
        delete temp; 
        return;
    }

    //general case
    while (current_child != nullptr){
        //if the next node is the child that needs to be removed
        if (current_child->get_x_coor() == x && current_child->get_y_coor() == y){
            prev_child->set_next(current_child->get_next());
            delete current_child;
            return;
        }else{
            prev_child = current_child;
            current_child = current_child->get_next();

        }
    }
}

//moving the children
void Game::moveChildren (double t) {
    Child *current_child = head_child;
    double x;
    double y;
    double distance;

    if (current_child == nullptr || t == 0) {
        numOfChildren();
        return;
    }

   if (t < 0.0) {
        while (current_child != nullptr){
            x = current_child->get_x_coor();
            y = current_child->get_y_coor();

            distance = sqrt(x*x + y*y);

            if (distance < 1.0) {
                removeChild(x, y);
            }
            current_child = current_child->get_next();
        }

        numOfChildren();
   }else{
        while (current_child != nullptr){
            x = current_child->get_x_coor();
            y = current_child->get_y_coor();

            double x_coor_change = t*cos(atan2(y,x));
            double y_coor_change = t*sin(atan2(y,x));

            x = x - x_coor_change;
            y = y - y_coor_change;

            current_child->set_x_coor(x);
            current_child->set_y_coor(y);

            if (x <= 0 || y <= 0){
                removeChild(x, y);
            }

            current_child = current_child->get_next();
        }

        numOfChildren();
   }
}

void Game::numOfChildren() { 
    int num_of_children = 0;
    Child *current_child = head_child;

    while (current_child != nullptr) {
        current_child = current_child->get_next();
        num_of_children ++;
    }

    std::cout << "number of children still playing: " << num_of_children << std::endl;
}

void Game::printChildren(double D){
    Child *current_child = head_child;
    int count = 0; 
    double x_coor;
    double y_coor;
    double distance;

    if (current_child == nullptr) {
        std::cout << "no children within distance" << std::endl;
        return;
    }

    while (current_child != nullptr){
        x_coor = current_child->get_x_coor();
        y_coor = current_child->get_y_coor();
        distance = sqrt ( (x_coor*x_coor) + (y_coor*y_coor) );

        if ( D > distance ){
            std::cout << x_coor << " " << y_coor << " "; 
            count ++;
        }

        current_child = current_child->get_next();
    }
   
    if (count == 0){
        std::cout << "no children within distance";
    }

    std::cout << std::endl; 
}

void Game::over(){

    if (head_child == nullptr) {
        std::cout << "the wolf wins" << std::endl;
    }else{
        std::cout << "the players win" << std::endl; 
    }
}

Child *Game::get_head_child(){
    return head_child;
}