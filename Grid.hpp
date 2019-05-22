//
//  Grid.hpp
//  Project2_GLOBAL_DETAILED
//
//  Created by khloud ghattas on 5/3/19.
//  Copyright © 2019 khloud ghattas. All rights reserved.
//

#ifndef Grid_hpp
#define Grid_hpp
#include <stdio.h>
#include<iostream>
#include "CellNode.hpp"
#include <vector>
using namespace std;
class Grid
{
public:
    int Width;
    int Height;
    vector <CellNode> CellNodes;
    int layerNumber;
	string layerName;
Grid();
Grid(int W, int H , int lN);
bool isvalid(CellNode cell);
void initializeCells();
void initializeCellsFromUsers(vector <CellNode> cNodes);
void Draw();
void Draw(vector<CellNode> path);
CellNode getCellNode(int X, int Y);
void setViaCellNode(int X, int Y , bool via);
};
#endif /* Grid_hpp */
