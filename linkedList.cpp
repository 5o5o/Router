//
//  linkedList.cpp
//  Mini project DD2
//
//  Created by khloud ghattas on 4/19/19.
//  Copyright © 2019 khloud ghattas. All rights reserved.
//


#include "linkedList.hpp"
#include <vector>
template <class Type>
linkedList<Type>::linkedList()
{
	Front = NULL;
	count = 0;
}
template <class Type>
void linkedList<Type>::addBack(Type element)
{
	NodePointer PN = new Node;
	PN->element = element;
	PN->next = NULL;
	PN->previous = NULL;
	if (isempty())
	{
		Front = PN;
		Rear = PN;
	}
	else
	{
		PN->previous = Rear;
		Rear->next = PN;
		Rear = PN;
	}
	count++;

}
template <class Type>
void linkedList<Type>::removeBack(Type& element)
{
	if (!isempty())
	{
		element = Rear->element;
		NodePointer curser = Rear;
		Rear->previous->next = NULL;
		Rear = Rear->previous;
		delete curser;
		count--;
		if (count == 0)
			Front = NULL;
	}

}
template <class Type>
void linkedList<Type>::removeFront(Type& element)
{
	if (!isempty())
	{
		element = Front->element;
		NodePointer curser = Front;
		Front = Front->next;
		delete curser;
		count--;
		if (count == 0)
			Rear = NULL;
	}

}
template <class Type>
void linkedList<Type>::getFront(Type& element)
{
	if (!isempty())
	{
		element = Front->element;
	}
}

template <class Type>
void linkedList<Type>::getBack(Type& element)
{
	if (!isempty())
	{
		element = Rear->element;
	}
}
template <class Type>
bool linkedList<Type>::isempty()
{
	return count == 0;
}
template <class Type>
std::vector<Type> linkedList<Type>::getList()
{
	std::vector<Type> targetList;
	if (!isempty())
	{
		NodePointer curser;
		curser = Front;
		while (curser != NULL)
		{
			targetList.push_back(curser->element);
			curser = curser->next;
		}
	}
	return targetList;
}
