//
//  RoutingPath.cpp
//  Project2_GLOBAL_DETAILED
//
//  Created by khloud ghattas on 5/3/19.
//  Copyright © 2019 khloud ghattas. All rights reserved.
//


#include "RoutingPath.hpp"
#include "CellNode.hpp"
#include <vector>
#include <iostream>
using namespace std;
RoutingPath::RoutingPath()
    {
        PathCost = 0;
    }
void RoutingPath::showPath()
    {
        vector <CellNode> targetList = TargetPath.getList();
        for (int i = 0; i < targetList.size(); i++)
        {
            targetList[i].showCell();
            cout << endl;
        }
        cout << PathCost << endl;
    }
