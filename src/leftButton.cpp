//
//  leftButton.cpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 22/02/2016.
//
//

#include "leftButton.hpp"
//The constructor of the class LeftButton takes the x, y, size and ofImage parameters from the InstructionButton class.
LeftButton::LeftButton(float _x, float _y, float _w, float _h, ofImage* _image): InstructionButton(_x, _y, _w, _h, _image){
}

//boolean for left instruction
bool LeftButton::choose(){
    //if left button in pressed the boolean will be set to true
    if(ofGetMouseX()>posX && ofGetMouseX()<posX+width && ofGetMouseY()>posY && ofGetMouseY()<posY+height){
        cout<<"LEFT"<<endl;
        return true;
        
    }
    return false;
}
