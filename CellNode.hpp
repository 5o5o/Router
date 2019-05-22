//
//  CellNode.hpp
//  Project2_GLOBAL_DETAILED
//
//  Created by khloud ghattas on 5/3/19.
//  Copyright © 2019 khloud ghattas. All rights reserved.
//

#ifndef CellNode_hpp
#define CellNode_hpp
#include <stdio.h>
#include <string>
class CellNode
{
public:
    int x;
    int y;
    double cost;
    double currentCost;
    bool isvia;
    char viaChar;
    bool isvisited;
    char obstcaleChar;
    char pathChar;
    int Ngrid;
    bool isobstacle;
	std::string LayerName;
	std::string compName;
	std::string pinName;
	int RectID;
	CellNode *uVia;
	CellNode *dVia;
	
    
    CellNode();
    
    CellNode(int cX, int cY, double cC, bool obst);
    
    CellNode(int cX, int cY, double cC, int nG , bool isobs, bool via);
    
    bool isequal(CellNode cell);
   
    
    bool operator == (const CellNode& cell);
    void showCell();
    
};

#endif /* CellNode_hpp */
