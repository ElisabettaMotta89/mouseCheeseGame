//
//  upButton.hpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 22/02/2016.
//
//

#ifndef upButton_hpp
#define upButton_hpp

#include <stdio.h>
#include "ofMain.h"
#include "instructionButton.hpp"

//Inherit the call InstructionButton
class UpButton: public InstructionButton {
public:


    // Create constructor for the UpButton object with coordinates, size and image as arguments
    UpButton(float _x, float _y, float _w, float _h, ofImage *_image);

    // Specify the different methods of the object UpButton
    virtual bool choose();

};

#endif /* upButton_hpp */
