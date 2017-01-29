//
//  Grid.hpp
//  EMotta_FinalProject
//
//  Created by Elisabetta Motta on 06/03/2016.
//
//

#ifndef Grid_hpp
#define Grid_hpp
#include "ofMain.h"
#include <stdio.h>

// class grid to draw the grid
class Grid
{
public:
    int row; // grid rows
    int col; // grid colums
    int x; //x position
    int y; // y position
    int blockSize; // block size
    int offSetx; // used for the grid
    int offSety; // used for the grid
    Grid(int _row, int _col, int _x, int _y, int _blocksize,int _ofSetx,int _ofSety); // constructor
    void display(); // display the grid
    void display_lose(); // display the red grid when a wrong move is done
    void display_win(); // display the green grid when the mouse catch the cheese
    bool select(); // select grid

};
#endif /* Grid_hpp */
