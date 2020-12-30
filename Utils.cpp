//
// Created by anarg on 12/30/2020.
//
#include "Utils.h"

string getRandomName(const string& file_name){
    ifstream input(file_name);
    if(!input){
        cerr << "Couldn't open file: "<< file_name << " !" <<endl;
    }
    string line;
    int nLines=0;
    while(getline(input,line)){
        ++nLines;
    }
    input.clear();
    input.seekg(0);
    for(int i=0;i<rand()%nLines;i++){
        getline(input,line);
    }
    input.close();
    return line;
}