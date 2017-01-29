//
//  rewindButton.cpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 02/03/2016.
//
//

#include "rewindButton.hpp"

//The constructor of the class RewindButton takes the x, y, size and ofImage parameters from the Button class.
RewindButton::RewindButton(float _x, float _y, float _w, float _h, ofImage* _image): Button(_x, _y, _w, _h, _image){
}

bool RewindButton::select(){
    //if rewind button in pressed the boolean will be set to true
    if(ofGetMouseX()>posX && ofGetMouseX()<posX+width && ofGetMouseY()>posY && ofGetMouseY()<posY+height){
        cout<<"REWIND"<<endl;
        return true;
        
    }
    return false;
}