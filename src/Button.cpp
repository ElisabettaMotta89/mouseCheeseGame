//
//  Button.cpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 15/02/2016.
//
//

#include "Button.hpp"

//Costructor
Button::Button(float _x, float _y, float _w, float _h, ofImage* _image):posX(_x), posY(_y), width(_w), height(_h), img(_image)
{
    stop = false; //set the boolean stop to false
}


void Button::display(){

    //Resize and display image
    img->draw(posX, posY, width, height);
}
