//
//  CellNode.cpp
//  Project2_GLOBAL_DETAILED
//
//  Created by khloud ghattas on 5/3/19.
//  Copyright © 2019 khloud ghattas. All rights reserved.
//


#include "CellNode.hpp"
#include <iostream>
using namespace std;

CellNode::CellNode()
    {
        x = 0;
        y = 0;
        cost = 0;
        currentCost = 0;
        isvia = false;
        obstcaleChar = '#';
        pathChar = '@';
        viaChar = 'V';
        Ngrid = 0;
        isvisited = false;
        isobstacle = false;
    }
CellNode::CellNode(int cX, int cY, double cC, bool obst)
    {
        x = cX;
        y = cY;
        cost = cC;
        currentCost = 0;
        isvia = false;
        obstcaleChar = '#';
        pathChar = '@';
        Ngrid = 0;
        isvisited = false;
        isobstacle = obst;
        viaChar = 'V';
    }
CellNode::CellNode(int cX, int cY, double cC, int nG , bool isobs, bool via)
    {
        x = cX;
        y = cY;
        cost = cC;
        Ngrid = nG;
        currentCost = 0;
        isvia = false;
        obstcaleChar = '#';
        pathChar = '@';
        viaChar = 'V';
        isvisited = false;
        isobstacle = isobs;
        isvia = via;
    }
bool CellNode:: isequal(CellNode cell)
    {
        return ((x == cell.x) && (y == cell.y) && Ngrid == cell.Ngrid);
        
    }
    
bool CellNode:: operator == (const CellNode& cell)
    {
        return ((x == cell.x) && (y == cell.y) && Ngrid == cell.Ngrid);
    }
    
void CellNode:: showCell()
    {
        cout << "(" << x << "," << y << ","<<Ngrid<<")";
    }

