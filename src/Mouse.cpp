//
//  Mouse.cpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 20/03/2016.
//
//

#include "Mouse.hpp"

//The constructor of the class PlayButton takes the x, y, size and ofImage parameters from the Button class.
Mouse::Mouse(float _x, float _y, ofImage* _image, Grid* _grid, ofTrueTypeFont* _font, Cheese* _cheese): Entity(_x, _y, _image, _grid), queue(27), stack(27), font(_font), cheese(_cheese){
    
}

void Mouse::move(){
    
    //change the frame rate to see every move of the mouse
    if(ofGetFrameNum()%20==0)
    {
        //create temporary string equal to the deQueue value
        string temp = queue.deQueue();
    
        //every time an instruction is added in the queue add the opposite instruction in the stack
        if(temp == "left")
        {
            posX = posX- grid->blockSize;
            stack.push("right");
            
        }
    
        if(temp == "right")
        {
            posX = posX+ grid->blockSize;
            stack.push("left");
        }
    
        if(temp == "up")
        {
            posY = posY- grid->blockSize;
            stack.push("down");
        }
        
        if(temp == "down")
        {
            posY = posY+ grid->blockSize;
            stack.push("up");
        }
    }
}

void Mouse::move_back(){
    
    //change the frame rate to see every move of the mouse
    if(ofGetFrameNum()%20==0)
    {
        //create temporary string equal to the deQueue value
        string temp1 = stack.pop();
        
        if(temp1 == "left")
        {
            posX = posX- grid->blockSize;
        }
        
        if(temp1 == "right")
        {
            posX = posX+ grid->blockSize;
        }
        
        if(temp1 == "up")
        {
            posY = posY- grid->blockSize;
        }
        
        if(temp1 == "down")
        {
            posY = posY+ grid->blockSize;
        }
    }
}


//boolean that check if mouse is outside the grid
bool Mouse::limit(){
    if(posX< grid->offSetx || posX> grid->offSetx + grid->blockSize*grid->row-grid->blockSize || posY< grid->offSety || posY> grid->offSety + grid->blockSize*grid->col-grid->blockSize)
    {
        return true;
    }
    return false;
    }

//the function limited draws the grid in red and it will tell the player to click to start again
void Mouse::lost(){
    ofPushStyle();
    ofSetColor(0, 0, 0);
    ofFill();
    font->drawString("Click on the grid to try again!",525,690);
    grid->display_lose();
    ofPopStyle();
}

//boolean to check if the mouse catched the cheese
bool Mouse::win(){
    if(posX == cheese->getX() && posY == cheese->getY())
    {
        return true;
    }
    return false;
}

//the function won draws the grid in green and it will tell the player to click to start again
void Mouse::won(){
    ofPushStyle();
    ofSetColor(0, 0, 0);
    ofFill();
    font->drawString("Well done! Click on the grid to play more!",430,690);
    grid->display_win();
    ofPopStyle();
}


//boolean to check if the mouse didn't catch the cheese
bool Mouse::loose(){
    if(posX != cheese->getX() && posY != cheese->getY())
    {
        return true;
    }
    return false;
}






