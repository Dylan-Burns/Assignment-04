

	//	LinkedBag340.cpp
	//	Created by: CSC340

	/*
	===>					<===
	===>  PLEASE ADD CODE	<===
	===>					<===
	*/
	#include "Include.h"
	#include <iostream>
	#include <cstddef>
	#include <cstdlib>		
	#include <ctime>		

	// operations:
	// 
	// step 1: check if the headNode.next != null
	//
	//		headNode -> secondNode -> null
	//					   ???
	// 
	// step 2: we want to assign headNode.next to the secondNode.next to 
	// 
	//		headNode    secondNode -> null
	//			|					   ^
	//			|______________________|
	//			
	// step 3: we want to assign secondNode.next = nullptr
	// 
	//		headNode		secondNode		null
	//			|			    `-> null	 ^
	//			|____________________________|
	// 
	// step 4: we want to remove the secondNode now that it has been unlinked from prevNode and nextNode
	//
	//		headNode -> null
	// this function removes the second node in the linked list //
	template<typename ItemType>
	bool LinkedBag<ItemType>::removeSecondNode340() {

		if (headPtr != nullptr) {

			auto secondNode = headPtr->getNext(); //reference to second Node

			headPtr->setNext(secondNode->getNext());
			secondNode->setNext(nullptr);

			itemCount--;

			return true;
		}

		return false;
	}
	// step 1: create a reference to the headNode
	// step 2: traverse linked list until node.next == null (end node found)
	// step 3: create the newNode, add its data, and set newNode.next == nullptr
	// step 3: assign the end node.next to the newNnode
	// step 4: make sure new node added to end points to null
	//
	// this function appends a new node to the end of the linked list
	template<typename ItemType>
	bool LinkedBag<ItemType>::addEnd340(const ItemType& newEntry) {

		auto currPtr = headPtr;

		while (currPtr->getNext() != nullptr) {
			currPtr = currPtr->getNext();
		}

		if (currPtr->getNext() == nullptr) {
			auto newNode = std::make_unique< Node<ItemType> >();
			newNode->setItem(newEntry);
			currPtr->setNext(newNode);
			itemCount++;
		}

		return true;
	}

	// step 1: create a count variable initialized to 0 to hold size value
	// step 2: create a while loop to traverse linked list to last node
	// step 3: increment count every iteration
	// step 4: return count
	// 
	//		count = 0
	// 
	//		Node -> Node -> Node -> Node -> null
	//		 `-> 1
	// 
	//		Node -> Node -> Node -> Node -> null
	//				 `-> 2
	// 
	//		Node -> Node -> Node -> Node -> null
	//						 `-> 3
	// 
	//		Node -> Node -> Node -> Node -> null
	//								 `-> 4
	// 
	//		currPtr->getNext() == nullptr -> EXIT LOOP
	// 
	//			count = 4
	//
	// this function iteratively traverses the linked list and returns its size
	template<typename ItemType>
	int LinkedBag<ItemType>::getCurrentSize340Iterative() const {

		int count = 0;

		auto currPtr = headPtr;

		while (currPtr != nullptr) {
			currPtr = currPtr->getNext();
			count++;
		}

		return count;
	}

	// This function uses an auxiliary function to compute the size of
	// the linked list (# of nodes) and return value back its caller
	//
	// this function uses the auxiliary function below to recursively traverse 
	// the linked list and find its size
	template<typename ItemType>
	int LinkedBag<ItemType>::getCurrentSize340Recursive() const {

		auto currPtr = headPtr;

		return getCurrentSize340RecursiveHelper(std::make_unique<Node<ItemType>>(currPtr));
	}

	// recursive auxiliary function
	// step 1: base case | check if headNode == null
	// step 2: return recursive function call passing headNode.next as a param
	// function will exit when base case is met ( node == null)
	//
	// this is an auxiliary function used by the function above
	template<typename ItemType>
	int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(std::unique_ptr< Node<ItemType> > currPtr) const {

		// base Case
		if (currPtr == nullptr) {
			return 0;
		}
		// count this node plus the rest of the list
		else {
			return 1 + getCurrentSize340RecursiveHelper(std::make_unique<Node<ItemType>>(currPtr->getNext()));
		}
	}

	// IMMEDIATE RECURSION
	// recursive function to compute linked list size without an auxiliary function
	// step 1: base case: check if headNode == null
	// step 2: return recursive function call passing headNode.next as param
	template<typename ItemType>
	int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {

		auto currPtr = headPtr;

		if (currPtr == nullptr) {
			return 0;
		}
		else {
			auto duplicate = LinkedBag(*this);
			duplicate.remove(duplicate.headPtr->getItem());

			return 1 + duplicate.getCurrentSize340RecursiveNoHelper();
		}
	}

	// this function uses an auziliary function to compute the size of the linked list
	template<typename ItemType>
	int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& anEntry) const {

		auto currPtr = headPtr;

		return getFrequencyOf340RecursiveHelper(std::make_unique<Node<ItemType>>(currPtr), anEntry);
	}

	// recursive auxiliary function
	// step 1: base case | check if headNode == null
	// step 2: return recursive function call passing headNode.next as a param
	// function will exit when base case is met ( node == null)
	// 
	// this is an auxiliary function used by the function above
	template<typename ItemType>
	int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(std::unique_ptr< Node<ItemType> > currPtr, const ItemType& anEntry) const {


		if (currPtr == nullptr) {
			return 0;
		}
		if (currPtr->getItem() == anEntry) {
			return 1 + getFrequencyOf340RecursiveHelper(std::make_unique< Node<ItemType> >((currPtr->getNext())), anEntry);
		}
		else {
			return getFrequencyOf340RecursiveHelper(std::make_unique< Node<ItemType> >((currPtr->getNext())), anEntry);
		}

	}


	// IMMEDIATE RECURSION
	// step 1: initialize count = 0 to track frequency

	// step 2: traverse linked list and increment count when match is found
	// step 3: return count
	template<typename ItemType>
	int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& anEntry) const {

		static auto currPtr = headPtr;
		int cases = 0;

		if (currPtr == nullptr) {
			currPtr = headPtr;

			return 0;
		}
		if (currPtr->getItem() == anEntry) {
			cases++;
			currPtr = currPtr->getNext();

			return cases + getFrequencyOf340RecursiveNoHelper(anEntry);
		}
		else {
			currPtr = currPtr->getNext();

			return cases + getFrequencyOf340RecursiveNoHelper(anEntry);
		}
	}

	template<typename ItemType>
	ItemType LinkedBag<ItemType>::removeRandom340() {

		int random = 0;
		int bagSize = getCurrentSize340Iterative();
		int min = 1;

		ItemType item;

		for (int i = 1; i <= bagSize; i++) {
			random = rand() % bagSize + min;
		}

		auto currPtr = headPtr;
		int nElement = random;

		for (int i = 0; i < (nElement - 2); i++) {
			currPtr = currPtr->getNext();
		}

		auto temp = currPtr->getNext();
		item = temp->getItem();
		remove(item);

		return item;
	}
