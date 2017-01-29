//
//  Entity.cpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 20/03/2016.
//
//

#include "Entity.hpp"

//Costructor
Entity::Entity(float _x, float _y, ofImage* _image, Grid* _grid):posX(_x), posY(_y), img(_image), grid(_grid)
{
}


void Entity::display(){
    
    //Resize and display image
    img->draw(posX, posY);
}


//random function to randomise the position in the grid
void Entity::random(){

    int rowN;
    int colN;
    
    rowN = ofRandom(grid->row);
    colN = ofRandom(grid->col);
    
    posX = grid->offSetx + (rowN * grid->blockSize);
    posY = grid->offSety + (colN * grid->blockSize);

}

//return protected variables to use them outside entity objects
float Entity::getX()
{
    return posX;
}

float Entity::getY()
{
    return posY;
}