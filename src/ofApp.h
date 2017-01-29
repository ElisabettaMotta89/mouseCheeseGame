#pragma once

#include "ofMain.h"
#include "Mouse.hpp"
#include "Cheese.hpp"
#include "playButton.hpp"
#include "rewindButton.hpp"
#include "randomButton.hpp"
#include "leftButton.hpp"
#include "rightButton.hpp"
#include "upButton.hpp"
#include "downButton.hpp"
#include "Grid.hpp"
#include "Queue.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        ofApp(); //ofApp constructor where you can initialise all the objects
        Grid grid; //grid object
        PlayButton play; //play object
        RewindButton rewind; //rewind object
        RandomButton random; //random object
        Mouse mouse; //mouse object
        Cheese cheese; //cheese object

        //image variables
        ofImage playImg;
        ofImage rewindImg;
        ofImage randomImg;
        ofImage leftImg;
        ofImage rightImg;
        ofImage upImg;
        ofImage downImg;
        ofImage mouseImg;
        ofImage cheeseImg;

        //font variable
        ofTrueTypeFont font;

        //unique pointer vectors
        vector<unique_ptr<InstructionButton>> instructions;
        vector<unique_ptr<InstructionButton>> directions;

        //offset, gap, maxSize and count variables
        int offsetY;
        int offsetX;
        float gap;

        int maxSize;
        int count_obj;

        //booleans
        bool play_game;
        bool re_wind;
        bool try_again;


};
