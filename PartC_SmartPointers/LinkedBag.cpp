//  LinkedBag.cpp
//  Created by Frank M. Carrano and Timothy M. Henry.
//	Updated by Duc Ta
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <cstddef>
#include "Node.h"
#include "LinkedBag.h"
#include <memory>


//
//
// PLEASE DO NOT CHANGE THIS FILE
//
//

template<typename ItemType>
//create head node and assign its pointer to null | headPtr -> null
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0) {}

template<typename ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag) {
	itemCount = aBag.itemCount;
	//create the first node and assign it to head
	auto origChainPtr = aBag.headPtr;

	//if there is not a next node assign headPtr.next to null
	if (origChainPtr == nullptr) {
		headPtr = nullptr; 
	}
	else {
		//link head pointe to new node in linked list
		headPtr = std::make_unique< Node<ItemType> >();
		//set head pointer data to same value as origChainPtr data
		headPtr->setItem(origChainPtr->getItem());

		auto newChainPtr = headPtr;
		origChainPtr = origChainPtr->getNext();

		while (origChainPtr != nullptr)
		{
			ItemType nextItem = origChainPtr->getItem();
			auto newNodePtr = std::make_unique< Node<ItemType> >(nextItem);
			newChainPtr->setNext(newNodePtr);
			newChainPtr = newChainPtr->getNext();
			origChainPtr = origChainPtr->getNext();
		} 

		newChainPtr->setNext(nullptr);
	}
}

template<typename ItemType>
LinkedBag<ItemType>::~LinkedBag() {
	clear();
} 

template<typename ItemType>
bool LinkedBag<ItemType>::isEmpty() const {
	return itemCount == 0;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize() const {
	return itemCount;
}

template<typename ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry) {
	auto nextNodePtr = std::make_unique< Node<ItemType> >();
	nextNodePtr->setItem(newEntry);
	nextNodePtr->setNext(headPtr);  
	headPtr = nextNodePtr;
	itemCount++;
	return true;
}

template<typename ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const {
	std::vector<ItemType> bagContents;
	auto curPtr = headPtr;
	int counter = 0;

	while ((curPtr != nullptr) && (counter < itemCount)) {
		bagContents.push_back(curPtr->getItem());
		curPtr = curPtr->getNext();
		counter++;
	}

	return bagContents;
}

//remove the node from the linked list
template<typename ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry) {
	auto entryNodePtr = getPointerTo(anEntry);
	//if the linked list is not empty and the node != null
	bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);

	if (canRemoveItem) {
		entryNodePtr->setItem(headPtr->getItem());
		auto nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();

		nodeToDeletePtr->setNext(nullptr);
		//delete nodeToDeletePtr;		//smart pointer has block scope so it is automatically destroyed
		//nodeToDeletePtr = nullptr;	// once function ends

		itemCount--;
	}

	return canRemoveItem;
}

template<typename ItemType>
void LinkedBag<ItemType>::clear() {
	auto nodeToDeletePtr = headPtr;

	while (headPtr != nullptr) {
		headPtr = headPtr->getNext();
		nodeToDeletePtr->setNext(nullptr);
		//delete nodeToDeletePtr;		//smart pointer has block scope so it is automatically destroyed
		//nodeToDeletePtr = nullptr;	// once function ends
	}

	itemCount = 0;
} 

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
	int frequency = 0;
	int counter = 0;
	auto curPtr = headPtr;

	while ((curPtr != nullptr) && (counter < itemCount)) {
		if (anEntry == curPtr->getItem()) {
			frequency++;
		} 
		counter++;
		curPtr = curPtr->getNext();
	}

	return frequency;
}

template<typename ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const {
	return (getPointerTo(anEntry) != nullptr);
}

template<typename ItemType>
std::unique_ptr< Node<ItemType> > LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const {
	bool found = false;
	//sets current node to headNode
	auto curPtr = headPtr;

	//search linked list starting from head until you reach null or find the node
	while (!found && (curPtr != nullptr)) {
		//if the node to be found = current node then we found the node
		if (anEntry == curPtr->getItem()) {
			found = true;
		}
		//else set current node to the next node
		else {
			curPtr = curPtr->getNext();
		}
	}

	return curPtr;
} 
