//
//  Mouse.hpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 20/03/2016.
//
//

#ifndef Mouse_hpp
#define Mouse_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Entity.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "Cheese.hpp"


//Inherit the call Button
class Mouse: public Entity {
public:
    
    Queue<string> queue;
    Stack<string> stack;
    Cheese* cheese;

    // Create constructor for the PlayButton object with coordinates, size and image as arguments
    Mouse(float _x, float _y, ofImage* _image, Grid* _grid, ofTrueTypeFont* _font, Cheese* _cheese);
    
    ofTrueTypeFont* font;
    void move();
    void move_back();
    bool loose();
    void lost();
    bool win();
    void won();
    bool limit();
    
};

#endif /* Mouse_hpp */
