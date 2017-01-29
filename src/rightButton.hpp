//
//  rightButton.hpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 22/02/2016.
//
//

#ifndef rightButton_hpp
#define rightButton_hpp

#include <stdio.h>
#include "ofMain.h"
#include "instructionButton.hpp"

//Inherit the call InstructionButton
class RightButton: public InstructionButton {
public:


    // Create constructor for the RightButton object with coordinates, size and image as arguments
    RightButton(float _x, float _y, float _w, float _h, ofImage* _image);

    // Specify the different methods of the object RightButton
    virtual bool choose();


};

#endif /* rightButton_hpp */
