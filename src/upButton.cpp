//
//  upButton.cpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 22/02/2016.
//
//

#include "upButton.hpp"
//The constructor of the class UpButton takes the x, y, size and ofImage parameters from the InstructionButton class.
UpButton::UpButton(float _x, float _y, float _w, float _h, ofImage *_image): InstructionButton(_x, _y, _w, _h, _image){
}
//if up button in pressed the boolean will be set to true
bool UpButton::choose(){
    //if up button in pressed the boolean will be set to true
    if(ofGetMouseX()>posX && ofGetMouseX()<posX+width && ofGetMouseY()>posY && ofGetMouseY()<posY+height){
        cout<<"UP"<<endl;
        return true;
        
    }
    return false;
}