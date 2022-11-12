//  Node.cpp
//  Created by Frank M. Carrano and Timothy M. Henry.
//	Updated by Duc Ta
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include "Node.h"
#include <memory>

//
//
// PLEASE DO NOT CHANGE THIS FILE
//
//

//creates a new node with no data and points to null (no nextNode)
template<typename ItemType>
Node<ItemType>::Node() : item(), next(nullptr) {}

//creates a new Node initialized with data and points to null
template<typename ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr) {}

//creates a new Node initialized with data and points to a nextNode
template<typename ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) :
	item(anItem), next(nextNodePtr) {} 

//sets caller data of the Node
template<typename ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) {
	item = anItem;
}

//sets caller Node.next 
template<typename ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {
	next = nextNodePtr;
}

//retrieves caller node data
template<typename ItemType>
ItemType Node<ItemType>::getItem() const {
	return item;
}

//retrieves caller Node.next
template<typename ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
	return next;
}
