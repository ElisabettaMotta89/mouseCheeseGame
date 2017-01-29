//
//  playButton.hpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 18/02/2016.
//
//

#ifndef playButton_hpp
#define playButton_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Button.hpp"

//Inherit the call Button
class PlayButton: public Button {
public:
    
    
    // Create constructor for the PlayButton object with coordinates, size and image as arguments
    PlayButton(float _x, float _y, float _w, float _h, ofImage* _image);
    
    // Specify the different methods of the object PlayButton
    bool select();
  

};

#endif /* playButton_hpp */
