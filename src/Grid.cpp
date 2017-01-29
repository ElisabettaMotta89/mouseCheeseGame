//
//  Grid.cpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 06/03/2016.
//
//

#include "Grid.hpp"

// constructor takes in rows, columns , position, blocksize, offests
Grid::Grid(int _row, int _col, int _x, int _y, int _blocksize,int _ofSetx,int _ofSety): row(_row),col(_col),x(_x),y(_y),blockSize(_blocksize),offSetx(_ofSetx),offSety(_ofSety)
{
    
}


void Grid::display()
{
    for (int j = 0; j < row; j++) {//loop through each row
        for (int i = 0; i < col; i++) {//loop through each column
            int x = i*blockSize+offSetx;
            int y = j*blockSize +offSety;
            
            //stroke
            ofPushStyle();
            ofSetColor(0);
            ofNoFill();
            
            //draw the board
            ofRect(x, y, blockSize, blockSize);
            //setting colour for ellipses
            ofPopStyle();
        }
        
    }
}

    
void Grid::display_lose()
{
    for (int j = 0; j < row; j++) {//loop through each row
        for (int i = 0; i < col; i++) {//loop through each column
            int x = i*blockSize+offSetx;
            int y = j*blockSize +offSety;
            
            //stroke
            ofPushStyle();
            ofSetColor(255,0,0,80);
            ofFill();
            //draw the board
            ofRect(x, y, blockSize, blockSize);
            //setting colour for ellipses
            ofPopStyle();
        }
        
    }
}

void Grid::display_win()
{
    for (int j = 0; j < row; j++) {//loop through each row
        for (int i = 0; i < col; i++) {//loop through each column
            int x = i*blockSize+offSetx;
            int y = j*blockSize +offSety;
            
            //stroke
            ofPushStyle();
            ofSetColor(0,255,0,80);
            ofFill();
            //draw the board
            ofRect(x, y, blockSize, blockSize);
            //setting colour for ellipses
            ofPopStyle();
        }
        
    }
}

bool Grid::select(){
    
if (ofGetMouseX()> offSetx &&ofGetMouseX()<offSetx+blockSize*row&&ofGetMouseY()>offSety&&ofGetMouseY()<offSety+blockSize*col)
{
    return true;
}
    return false;
    
}


