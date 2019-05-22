//
//  linkedList.hpp
//  Mini project DD2
//
//  Created by khloud ghattas on 4/19/19.
//  Copyright © 2019 khloud ghattas. All rights reserved.
//

#ifndef linkedList_hpp
#define linkedList_hpp

#include <stdio.h>
#include <vector>
template <class Type>
class linkedList
{
public:
	class Node
	{
	public:
		Type element;
		Node* next;
		Node* previous;
	};
	typedef Node* NodePointer;
	NodePointer Front;
	NodePointer Rear;
	int count;
	linkedList();
	void addBack(Type);
	void removeBack(Type&);
	bool isempty();
	void removeFront(Type&);
	void getFront(Type&);
	void getBack(Type&);
	std::vector <Type> getList();
};


#endif /* linkedList_hpp */
