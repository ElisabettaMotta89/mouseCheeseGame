//
//  playButton.cpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 18/02/2016.
//
//

#include "playButton.hpp"

//The constructor of the class PlayButton takes the x, y, size and ofImage parameters from the Button class.
PlayButton::PlayButton(float _x, float _y, float _w, float _h,  ofImage* _image): Button(_x, _y, _w, _h, _image){
}

bool PlayButton::select(){
    //if play button in pressed the boolean will be set to true
    if(ofGetMouseX()>posX && ofGetMouseX()<posX+width && ofGetMouseY()>posY && ofGetMouseY()<posY+height){
        cout<<"PLAY"<<endl;
        return true;
        
    }
    return false;
}
