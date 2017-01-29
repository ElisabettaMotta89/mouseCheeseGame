//
//  leftButton.hpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 22/02/2016.
//
//

#ifndef leftButton_hpp
#define leftButton_hpp

#include <stdio.h>
#include "ofMain.h"
#include "instructionButton.hpp"

//Inherit the call InstructionButton
class LeftButton: public InstructionButton {
public:


    // Create constructor for the LeftButton object with coordinates, size and image as arguments
    LeftButton(float _x, float _y, float _w, float _h, ofImage* _image);

    // Specify the different methods of the object LeftButton
    virtual bool choose();

};

#endif /* leftButton_hpp */
