//
// Created by anarg on 1/4/2021.
//

#include "Grid.h"

Grid::Grid(Party* party,int max_x, int max_y):party(party),MAX_X(max_x),MAX_Y(max_y),x(max_x/2),y(max_y/2)
{
    for(int j=0;j<MAX_Y;j++){
        grid.push_back(vector<Block*>());
        for(int i=0;i<MAX_X;i++){
            int type=rand()%10;
            int distance=abs(((MAX_X/2)-i) + ((MAX_Y)-j));
            cout << distance <<"<---"<< endl;
            switch (type) {
                case 1:
                    cout << "Market"<<endl;
                    grid[j].push_back(new Market(distance+party->getLevel()));
                    break;
                case 2:
                    cout << "Non access"<<endl;
                    grid[j].push_back(new NonAccessible());
                    break;
                default:
                    cout << "Common"<<endl;
                    grid[j].push_back(new Common(distance+party->getLevel()));
                    break;
            }
        }
    }

}



void Grid::print() {
    for(int j=MAX_Y-1;j>=0;j--){
        for(int i=0;i<MAX_Y;i++){
            if(x==i && y==j){
                cout << "[P]";
              //  grid[i][j]->printBlock();
              //  cout << "(x:"<<i<<",y:"<<j<<")";
            }else{
                grid[i][j]->printBlock();
            //   cout << "(x:"<<i<<",y:"<<j<<")";
            }
        }
        cout <<endl;
    }
}
void Grid::moveUp() {
    if(y+1<MAX_Y && grid[x][y + 1]->isAccessible()){
        y++;
    }else{
        cout << "Can't go there!"<<endl;
        return;
    }
    grid[x][y]->event(party);
    print();
}


void Grid::moveDown() {
    if(y-1>=0 && grid[x][y - 1]->isAccessible()){
        y--;
    }
    else{
        cout << "Can't go there!"<<endl;
        return;
    }
    grid[x][y]->event(party);
    print();
}

void Grid::moveLeft() {
    if(x-1>=0 && grid[x - 1][y]->isAccessible()){
        x--;
    }
    else{
        cout << "Can't go there!"<<endl;
        return;
    }
    grid[x][y]->event(party);
    print();
}

void Grid::moveRight() {
    if(x+1<MAX_X && grid[x + 1][y]->isAccessible()){
        x++;
    }
    else{
        cout << "Can't go there!"<<endl;
        return;
    }
    grid[x][y]->event(party);
    print();
}