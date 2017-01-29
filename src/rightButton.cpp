//
//  rightButton.cpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 22/02/2016.
//
//

#include "rightButton.hpp"
//The constructor of the class RightButton takes the x, y, size and ofImage parameters from the InstructionButton class.
RightButton::RightButton(float _x, float _y, float _w, float _h, ofImage* _image): InstructionButton(_x, _y, _w, _h, _image){
}

//boolean for right instruction
bool RightButton::choose(){
    //if right button in pressed the boolean will be set to true
    if(ofGetMouseX()>posX && ofGetMouseX()<posX+width && ofGetMouseY()>posY && ofGetMouseY()<posY+height){
        cout<<"RIGHT"<<endl;
        return true;
        
    }
    return false;
}