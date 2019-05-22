//
//  Maze.cpp
//  Project2_GLOBAL_DETAILED
//
//  Created by khloud ghattas on 5/3/19.
//  Copyright © 2019 khloud ghattas. All rights reserved.
//


#include "Maze.hpp"
#include "CellNode.hpp"
#include "Grid.hpp"
//#include "RoutingPath.hpp"
#include "Node.hpp"
#include <iostream>
#include <vector>
#include <set>
using NodeSet = std::set<Node*>;
Maze::Maze()
    {
        nlayer = 1;
        targetRoutePath = RoutingPath();
        
    }
Maze::Maze(int ML)
    {
        nlayer = ML;
        initializeMazes();
    }
    void Maze:: initializeMazes()
    {
        Grid grid(10, 10 , 0);
        Grids.push_back(grid);
    }
    void Maze::initializeMazesFromUsers(int W, int H, int ML)
    {
        nlayer = ML;
        for (int i = 0; i<ML; i++)
        {
            Grid grid(W, H,i);
            Grids.push_back(grid);
        }
    }
    void Maze::DrawMaze()
    {
        for (int i = 0; i< nlayer; i++)
        {
            Grids[i].Draw();
            
        }
    }
    void Maze::DrawMaze(vector<CellNode> path)
    {
        for (int i = 0; i< nlayer; i++)
        {
            Grids[i].Draw(path);
            
        }
    }
    bool Maze::setSource(int X, int Y, int Ngrid)
    {
        cSource = Grids[Ngrid].getCellNode(X, Y);
        nlS = Ngrid;
        return true;
    }
    bool Maze::setTarget(int X, int Y, int Ngrid)
    {
        cTarget = Grids[Ngrid].getCellNode(X, Y);
        nlT = Ngrid;
        return true;
    }
    void Maze::setVia(int X, int Y)
    {
        for(int i=0 ; i<nlayer ; i++)
            Grids[i].setViaCellNode(X, Y,true);
    }
    CellNode Maze::getCellNode(int X, int Y, int Ngrid)
    {
        return Grids[Ngrid].getCellNode(X, Y);
    }
    
    RoutingPath Maze::findPath_AStar()
    {
        RoutingPath targetPath;
        targetPath = findPath_AStar(cSource, cTarget, nlS, nlT);
        return targetPath;
    }
    
    RoutingPath Maze::findPath_AStar(int X1, int Y1, int N1, int X2, int Y2, int N2)
    {
        RoutingPath targetPath;
        setSource(X1, Y1, N1);
        setSource(X2, Y2, N2);
        return targetPath;
    }
    
    int Maze::getNextLayer(int nL)
    {
        if (nL == 0 && cTarget.Ngrid > 0 )
            return nL + 1;
        else if (nL == 1 && cTarget.Ngrid > 1 )
            return nL + 1;
        else if (nL == 1 && cTarget.Ngrid < 1 )
            return nL - 1;
        else if (nL == 2 && cTarget.Ngrid < 2 )
            return nL - 1;
        else
            return nL;
        
    }
    
    using NodeSet = std::set<Node*>;
    RoutingPath Maze::findPath_AStar(CellNode Source, CellNode Target, int nlS, int nlT)
    {
        RoutingPath targetPath;
        vector<CellNode> closedSet;
        vector<CellNode> openSet;
        NodeSet copenset;
        NodeSet cclosedSet;
        copenset.insert(new Node(Source));
        openSet.push_back(Source);
        CellNode current;
        Node* cCurrent = nullptr;
        vector <int> rD = { 1,-1,0,0,0 };
        vector <int> cD = { 0,0,1,-1,0 };
        int currentCost = 0;
        int SucCost = 0;
        while (!openSet.empty())
        {
            current = openSet[0];
            
            for (int i = 0; i< openSet.size(); i++)
            {
                if (openSet[i].currentCost < current.currentCost)
                {
                    current = openSet[i];
                }
            }
            cCurrent = *copenset.begin();
            for (auto node : copenset) {
                if (node->element == current) {
                    cCurrent = node;
                }
            }
            currentCost = current.currentCost;
            closedSet.push_back(current);
            cclosedSet.insert(cCurrent);
            
            if (current.isequal(Target))
            {
                break;
            }
            
            openSet.erase(find(openSet.begin(), openSet.end(), current));
            
            for (int i = 0; i < 5; i++)
            {
                int X = current.x + rD[i];
                int Y = current.y + cD[i];
                bool isViaCell = false;
                if (i == 4) {
                    if (!current.isvia)
                        continue;
                    else
                        isViaCell = true;
                }
                if ((X >= 0 && X < Grids[0].Width && Y >= 0 && Y < Grids[0].Height))
                {
                    int nL = current.Ngrid;
                    if (isViaCell)
                        nL = getNextLayer(nL);
                    
                    CellNode Neighbour = getCellNode(current.x + rD[i], current.y + cD[i], nL);
                    if (Neighbour.isobstacle)
                        continue;
                    bool isinOpenL = false;
                    for (int i = 0; i < openSet.size(); i++)
                    {
                        if (Neighbour.isequal(openSet[i]))
                        {
                            Neighbour = openSet[i];
                            isinOpenL = true;
                        }
                        
                    }
                    
                    bool isv = false;
                    for (int i = 0; i < closedSet.size(); i++)
                    {
                        if (Neighbour.isequal(closedSet[i]))
                        {
                            Neighbour = closedSet[i];
                            isv = true;
                        }
                    }
                    
                    SucCost = current.currentCost+ Neighbour.cost;
                    Node* cNeighbor = new Node(Neighbour);
                    if (isinOpenL)
                    {
                        if (SucCost >= Neighbour.currentCost) continue;
                    }
                    else if(isv && !(Neighbour.isequal(Source)))
                    {
                        if (SucCost >= Neighbour.currentCost)
                            continue;
                        closedSet.erase(find(closedSet.begin(), closedSet.end(), Neighbour));
                        openSet.push_back(Neighbour);
                        cNeighbor->parent = cCurrent;
                        copenset.insert(cNeighbor);
                    }
                    else if(!(Neighbour.isequal(Source)))
                    {
                        Neighbour.isvisited = true;
                        Neighbour.currentCost = SucCost;
                        openSet.push_back(Neighbour);
                        copenset.insert(cNeighbor);
                    }
                    cNeighbor->parent = cCurrent;
                    
                }
            }
            
        }
        
        // A* algorithim
        while (cCurrent != NULL || cCurrent!= nullptr)
        {
            targetRoutePath.TargetPath.addBack(cCurrent->element);
            cCurrent = cCurrent->parent;
        }
        
        targetRoutePath.PathCost = currentCost;
        return targetRoutePath;
    }
