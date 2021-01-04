//
// Created by anarg on 1/4/2021.
//

#ifndef UNTITLED1_GRID_H
#define UNTITLED1_GRID_H
#include "vector"
#include "Market.h"
#include "Common.h"
#include "NonAccessible.h"
#include "Party.h"

class Grid {
private:
    vector<vector <Block*>> grid;
    Party* party;
    int x;
    int y;
    const int MAX_X;
    const int MAX_Y;
public:
    Grid(Party* party,int max_x,int max_y);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void print();
};


#endif //UNTITLED1_GRID_H
