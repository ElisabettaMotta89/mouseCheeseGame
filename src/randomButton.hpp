//
//  randomButton.hpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 20/03/2016.
//
//

#ifndef randomButton_hpp
#define randomButton_hpp

#include <stdio.h>
#include "Button.hpp"
#include "Mouse.hpp"
#include "Cheese.hpp"


//Inherit the call Button
class RandomButton: public Button {
public:
    
    Mouse *mouse;
    Cheese *cheese;
    
    // Create constructor for the RandomButton object with coordinates, size and image as arguments
    RandomButton(float _x, float _y, float _w, float _h, ofImage* _image, Mouse* _mouse, Cheese* _cheese);
    
    // Specify the different methods of the object RandomButton
    bool select();
    void selected();
    
    
};


#endif /* randomButton_hpp */
