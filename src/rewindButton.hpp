//
//  rewindButton.hpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 02/03/2016.
//
//

#ifndef rewindButton_hpp
#define rewindButton_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Button.hpp"

//Inherit the call Button
class RewindButton: public Button {
public:
    
    
    // Create constructor for the RewindButton object with coordinates, size and image as arguments
    RewindButton(float _x, float _y, float _w, float _h, ofImage* _image);
    
    // Specify the different methods of the object RewindButton
    bool select();
    
    
};


#endif /* rewindButton_hpp */
