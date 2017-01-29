//
//  randomButton.cpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 20/03/2016.
//
//

#include "randomButton.hpp"
//The constructor of the class RandomButton takes the x, y, size and ofImage parameters from the Button class. It also takes the mouse and cheese objects.
RandomButton::RandomButton(float _x, float _y, float _w, float _h, ofImage* _image, Mouse* _mouse, Cheese* _cheese): Button(_x, _y, _w, _h, _image), mouse(_mouse), cheese(_cheese){
}

bool RandomButton::select(){
    //if random button in pressed the boolean will be set to true
    if(ofGetMouseX()>posX && ofGetMouseX()<posX+width && ofGetMouseY()>posY && ofGetMouseY()<posY+height){
        return true;
        
    }
    return false;
}

void RandomButton::selected(){
    //if the selected function is called, the random function of mouse and cheese will be called.
    mouse->random();
    cheese->random();
    
    //check if the mouse is in the same position of the cheese and randomise again
    if(mouse->getX()==cheese->getX()&&mouse->getY()==cheese->getY())
    {
        mouse->random();
        cheese->random();
        cout<<"funziona"<< endl;
    }
    
}