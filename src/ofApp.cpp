#include "ofApp.h"


//create new objects PlayButton, RewindButton, RandomButton, mouse, cheese and grid
ofApp::ofApp():
play(192, 550, 100, 100, &playImg),
rewind(292, 550, 100, 100, &rewindImg),
random(35, 550, 100, 100, &randomImg, &mouse, &cheese),
cheese(520, 102, &cheeseImg, &grid),
mouse(470, 102, &mouseImg, &grid, &font, &cheese),
grid(10,10,0,0,50,470,100)



{}
//--------------------------------------------------------------
void ofApp::setup(){
    
    //load font
    font.loadFont("font.ttf",20);
    
    //load images
    playImg.load("play.png");
    rewindImg.load("rewind.png");
    randomImg.load("random.png");
    leftImg.load("left.png");
    rightImg.load("right.png");
    upImg.load("up.png");
    downImg.load("down.png");
    cheeseImg.load("cheese.png");
    mouseImg.load("mouse.png");
    
    
    //call random function of mouse and cheese objects to randomise them from the beginning.
    mouse.random();
    cheese.random();
    
    //Create 4 instructionButton of type leftButton, rightButton, downButton, upButton
    InstructionButton*left = new LeftButton(45, 130, 80, 80, &leftImg);
    InstructionButton*right = new RightButton(45, 215, 80, 80, &rightImg);
    InstructionButton*up = new UpButton(45, 300, 80, 80, &upImg);
    InstructionButton*down = new DownButton(45, 385, 80, 80, &downImg);

    instructions.emplace_back(left);
    instructions.emplace_back(right);
    instructions.emplace_back(up);
    instructions.emplace_back(down);
    
    //set variables and booleans
    offsetY = 130;
    offsetX = 0;
    gap = 0;
    maxSize = 27;
    count_obj = 0;
    play_game = false;
    re_wind = false;
    try_again = false;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){ 

//when play_game boolean is true call the move function of mouse
   if(play_game)
   {
        mouse.move();
   }

//when the queue is empty set the play_game boolean to false and the booleans stop back to true
    if(mouse.queue.isEmpty() && mouse.win())
    {
        play_game = false;
        
            random.stop = true;
            rewind.stop = true;
            
            for(auto &in:instructions)
            {
                in->stop = true;
            }
        
    }
    


//when the boolean limit in the mouse object is set to true call deQueue and the limited function in the mouse object
    if(mouse.limit()){
    
        mouse.queue.deQueue();
    }

//when the boolean try_again is true the move_back function of the mouse object will be called and the mouse will move back to the initial point. Also the boolean stop of each button will be set back to false for the player to be able to use them again. This will also set the variables to display the directions one under the other back to 0.
    if(try_again)
    {
        mouse.move_back();
        
        random.stop = false;
        rewind.stop = false;
        
        for(auto &in:instructions)
        {
            in->stop = false;
        }
        
        gap = 0;
        count_obj = 0;
        offsetX = 0;
    }
    
//when the stack is empty set the boolean try_again back to false
    if(mouse.stack.isempty())
    {
        try_again = false;
    }

//when the select function of the rewind button is called, call deQueue and isEmpty function of the queue in the mouse object
    if(re_wind)
    {
        mouse.queue.deQueue();
        mouse.queue.isEmpty();
    }

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //draw lines to delimitate spaces
    ofBackground(255, 255, 255);
    ofPushStyle();
    ofSetColor(0);
    ofDrawLine(170, 0, 170, ofGetHeight());
    ofDrawLine(414, 0, 414, ofGetHeight());
    ofPopStyle();
    
    //display play, random and rewind button
    play.display();
    rewind.display();
    random.display();
    
    //display all instruction buttons
    for (auto &im:instructions)
    {
        im->display();
    }
    
    //display all direction buttons
    for (auto &di:directions)
    {
        di->display();
    }
    
    //display grid
    grid.display();
    
    //set variables to change column
    if (gap > 320 ) {
        offsetX+= 50;
        gap = 0;
    }
    
    //display mouse and cheese
    cheese.display();
    mouse.display();
    
    
    // when the boolean limit of the mouse object is true set the boolean stop for each button
    if(mouse.limit()){
        
        random.stop = true;
        rewind.stop = true;
        
        for(auto &in:instructions)
        {
            in->stop = true;
        }
    }
    
    //when the queue is empty and mouse.win is true call the function mouse.won
    if (mouse.queue.isEmpty() && mouse.win()) {
        mouse.won();
    }
    
    
    //when the queue is empty, mouse.loose is true and play_game is true call the function mouse.lost and set all the booleans stop back to true
    if (mouse.queue.isEmpty() && mouse.loose() && play_game) {
        mouse.lost();
        random.stop = true;
        rewind.stop = true;
        
        for(auto &in:instructions)
        {
            in->stop = true;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){


if (grid.select() && mouse.loose())
{
    //when the grid is pressed and mouse.loose is true the boolean try_again will be set to true and play_game will be set to false. Also the directions vector will be cleared.
        try_again = true;
        play_game = false;
    
        directions.clear();
    }

    
//when the grid is pressed and mouse.win is true the boolean stop will be all set back to false and the selected function of random will be called, the directions will be cleared and the stack will be popped to delate all the instructions in it.
if (grid.select() && mouse.win()) {
        
        random.stop = false;
        rewind.stop = false;
        
        for(auto &in:instructions)
        {
            in->stop = false;
        }
    
    random.selected();
    directions.clear();
    gap = 0;
    count_obj = 0;
    offsetX = 0;
    play_game = false;
    re_wind = true;
    mouse.stack.setTop(-1);
    }
    
    
    //call the select function of the random button to randomise the position of cheese and mouse in the grid. ALso set the queue back to 0 and play_game to false. This will also set the variables to display the directions one under the other back to 0.

    if(random.select() && !random.stop)
    {
        random.selected();
        directions.clear();
        mouse.queue.setBack(0);
        mouse.queue.setFront(0);
        play_game = false;
        gap = 0;
        count_obj = 0;
        offsetX = 0;
        
    }
    
    //call the select function of the rewind button to clear the directions vector and to set the play_game boolean to false and re_wind to true. This will also set the variables to display the directions one under the other back to 0.

    if(rewind.select()&& ! rewind.stop)
    {
        directions.clear();
        gap = 0;
        count_obj = 0;
        offsetX = 0;
        mouse.queue.setBack(0);
        mouse.queue.setFront(0);
        play_game = false;
        re_wind = true;
    }
    
    
//call choose for each instruction pressed
    for(int i = 0; i<instructions.size();i++){
   
        instructions[i]->choose();
    }
    
//if left instruction is pressed, the vector size is less than 27 and stop is set to false, create a new direction pointer of type LeftButton and add the relative instruction in the queue vector in the mouse object
    if(instructions[0]->choose()&&count_obj<maxSize && !instructions[0]->stop)
    {
        directions.emplace_back(new LeftButton(225+offsetX, offsetY+gap, 40, 40, &leftImg));
        gap+=40;
        count_obj++;
        mouse.queue.enQueue("left");
       
    }
//if right instruction is pressed, the vector size is less than 27 and stop is set to false, create a new direction pointer of type RightButton and add the relative instruction in the queue vector in the mouse object
    if(instructions[1]->choose()&&count_obj<maxSize&& !instructions[1]->stop)
    {
        directions.emplace_back(new RightButton(225+offsetX, offsetY+gap, 40, 40, &rightImg));
        gap+=40;
        count_obj++;
        mouse.queue.enQueue("right");
        
    }
//if up instruction is pressed, the vector size is less than 27 and stop is set to false, create a new direction pointer of type UpButton and add the relative instruction in the queue vector in the mouse object
    if(instructions[2]->choose()&&count_obj<maxSize&& !instructions[2]->stop)
    {
        directions.emplace_back(new UpButton(225+offsetX, offsetY+gap, 40, 40, &upImg));
        gap+=40;
        count_obj++;
        mouse.queue.enQueue("up");

    }
//if down instruction is pressed, the vector size is less than 27 and stop is set to false, create a new direction pointer of type DownButton and add the relative instruction in the queue vector in the mouse object
    if(instructions[3]->choose()&&count_obj<maxSize&& !instructions[3]->stop)
    {
        directions.emplace_back(new DownButton(225+offsetX,offsetY+gap, 40, 40, &downImg));
        gap+=40;
        count_obj++;
        mouse.queue.enQueue("down");

    }
    
//call the select function of the play button to make the mouse following the instructions in the queue
    if(play.select())
    {
        play_game = true;
        
    }
    


    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
//set re_wind back to false when the mouse is released
    re_wind = false;

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
