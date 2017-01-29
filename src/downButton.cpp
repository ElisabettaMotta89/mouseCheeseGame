//
//  downButton.cpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 22/02/2016.
//
//

#include "downButton.hpp"
//The constructor of the class DownButton takes the x, y, size and ofImage parameters from the InstructionButton class.
DownButton::DownButton(float _x, float _y, float _w, float _h, ofImage *_image): InstructionButton(_x, _y, _w, _h, _image){
}

//if down button in pressed the boolean will be set to true
bool DownButton::choose(){
    //if down button in pressed the boolean will be set to true
    if(ofGetMouseX()>posX && ofGetMouseX()<posX+width && ofGetMouseY()>posY && ofGetMouseY()<posY+height){
        cout<<"DOWN"<<endl;
        return true;
        
    }
    return false;
}