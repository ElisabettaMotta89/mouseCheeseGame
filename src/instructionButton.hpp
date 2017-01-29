//
//  instructionButton.hpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 18/02/2016.
//
//

#ifndef instructionButton_hpp
#define instructionButton_hpp

#include <stdio.h>

#include "ofMain.h"
#include "Button.hpp"

//Inherit the call Button
class InstructionButton: public Button {
public:
        
    // Create constructor for the InstructionButton object with coordinates, size and image as arguments
    InstructionButton(float _x, float _y, float _w, float _h, ofImage* _image);
    
    // Specify the different methods of the object InstructionButton
    virtual bool choose();
    
};

#endif /* instructionButton_hpp */
