//
//  Button.hpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 15/02/2016.
//
//

#ifndef Button_hpp
#define Button_hpp

#include <stdio.h>
#include "ofMain.h"
//Create a class for a base button that would be inherited by the PlayButton and the Instruction buttons.
class Button {
public:
    bool stop;
    //Define constructor. It will take 3 arguments: x, y, h, w and an image.
    Button(float _x, float _y, float _w, float _h, ofImage* _image);

    //Define methods.
    void display();

protected:
    
    //Define variables.
    ofImage* img;
    float posX;
    float posY;
    float width;
    float height;
    
    
};

#endif /* Button_hpp */
