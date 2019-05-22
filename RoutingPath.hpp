//
//  RoutingPath.hpp
//  Project2_GLOBAL_DETAILED
//
//  Created by khloud ghattas on 5/3/19.
//  Copyright © 2019 khloud ghattas. All rights reserved.
//

#ifndef RoutingPath_hpp
#define RoutingPath_hpp
#include <iostream>
#include <stdio.h>
#include <vector>
#include "CellNode.hpp"
#include "linkedList.hpp"
#include "linkedList.cpp"
#include "string"
class RoutingPath
{
    public:
    linkedList <CellNode> TargetPath;
    double PathCost;
    RoutingPath();
    void showPath();
	std::string getstringPath();
};
#endif /* RoutingPath_hpp */
