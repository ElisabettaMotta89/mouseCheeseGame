//
//  downButton.hpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 22/02/2016.
//
//

#ifndef downButton_hpp
#define downButton_hpp

#include <stdio.h>
#include "ofMain.h"
#include "instructionButton.hpp"

//Inherit the call InstructionButton
class DownButton: public InstructionButton {
public:


    // Create constructor for the DownButton object with coordinates, size and image as arguments
    DownButton(float _x, float _y, float _w, float _h, ofImage *_image);

    // Specify the different methods of the object DownButton
    virtual bool choose();

};

#endif /* downButton_hpp */
