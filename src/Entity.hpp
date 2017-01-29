//
//  Entity.hpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 20/03/2016.
//
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Grid.hpp"
//Create a class for a base entity that would be inherited by the Mouse and the Cheese classes.
class Entity {
public:

    //Define constructor. It will take 3 arguments: x, y, h, w and an image.
    Entity(float _x, float _y, ofImage* _image, Grid* _grid);

    //Define methods.
    void display();
    void random();
    float getX();
    float getY();

protected:

    //Define variables.
    ofImage* img;
    float posX;
    float posY;
    Grid *grid;


};


#endif /* Entity_hpp */
