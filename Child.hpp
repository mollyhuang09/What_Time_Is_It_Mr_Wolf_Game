#ifndef CHILD_HPP
#define CHILD_HPP

#include <iostream>
#include <string>
 
class Child {
public: 

    Child(double x, double y);

    ~Child();

    void set_next( Child *new_next_child );

    double get_x_coor();

    double get_y_coor();

    void set_x_coor(double x);
    
    void set_y_coor(double y);

    Child *get_next();

private:
    double x_coor;
    double y_coor;
    Child *next_child;

};

#endif 