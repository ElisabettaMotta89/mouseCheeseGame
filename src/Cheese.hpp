//
//  Cheese.hpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 20/03/2016.
//
//

#ifndef Cheese_hpp
#define Cheese_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Entity.hpp"

//Inherit the call Button
class Cheese: public Entity {
public:
        
    // Create constructor for the PlayButton object with coordinates, size and image as arguments
    Cheese(float _x, float _y, ofImage* _image, Grid* _grid);
    
};


#endif /* Cheese_hpp */
