//
//  Maze.hpp
//  Project2_GLOBAL_DETAILED
//
//  Created by khloud ghattas on 5/3/19.
//  Copyright © 2019 khloud ghattas. All rights reserved.
//

#ifndef Maze_hpp
#define Maze_hpp
#include <stdio.h>
#include <vector>
#include <set>
#include "CellNode.hpp"
#include "Grid.hpp"
#include "RoutingPath.hpp"
#include "Node.hpp"
using namespace std;
class Maze
{
public:
    int nlayer;
    CellNode cSource;
    CellNode cTarget;
    int nlS, nlT;
    RoutingPath targetRoutePath;
    vector <Grid> Grids;
    Maze();
    Maze(int ML);
    void initializeMazes();
    void initializeMazesFromUsers(int W, int H, int ML);
    void DrawMaze();
    void DrawMaze(vector<CellNode> path);
    bool setSource(int X, int Y, int Ngrid);
    bool setTarget(int X, int Y, int Ngrid);
    void setVia(int X, int Y);
    CellNode getCellNode(int X, int Y, int Ngrid);
    RoutingPath findPath_AStar();
    RoutingPath findPath_AStar(int X1, int Y1, int N1, int X2, int Y2, int N2);
    int getNextLayer(int nL);
    RoutingPath findPath_AStar(CellNode , CellNode , int , int);
};
#endif /* Maze_hpp */
