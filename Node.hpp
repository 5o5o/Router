#pragma once
//
//  Node.hpp
//  Project2_GLOBAL_DETAILED
//
//  Created by khloud ghattas on 5/3/19.
//  Copyright © 2019 khloud ghattas. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp
#include "CellNode.hpp"
#include <stdio.h>
class Node
{
public:
	CellNode element;
	Node* next;
	Node* parent;
	Node(CellNode cell);
	~Node();

};
#endif /* Node_hpp */
