#include "LinkedBag.h"
#include <cstdlib>




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

		Node<ItemType>* secondNode = headPtr->getNext(); //reference to second Node

		headPtr->setNext(secondNode->getNext());
		secondNode->setNext(nullptr);

		delete secondNode;
		secondNode = nullptr;
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
	
	Node<ItemType>* currPtr = headPtr;

	while (currPtr != nullptr) {
		currPtr = currPtr->getNext();
	}

	Node<ItemType>* newNode{ newEntry, nullptr };

	currPtr->setNext(newNode);
	return  (currPtr->getNext() == newNode);
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

	Node<ItemType>* currPtr = headPtr;
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
	return getCurrentSize340RecursiveHelper();
}

// recursive auxiliary function
// step 1: base case | check if headNode == null
// step 2: return recursive function call passing headNode.next as a param
// function will exit when base case is met ( node == null)
//
// this is an auxiliary function used by the function above
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* currPtr) const {

	// base Case
	if (currPtr == nullptr) {
		return 0;
	}
	// count this node plus the rest of the list
	else {
		return 1 + getCurrentSize340RecursiveHelper(currPtr->getNext());
	}
}

// IMMEDIATE RECURSION
// recursive function to compute linked list size without an auxiliary function
// step 1: base case: check if headNode == null
// step 2: return recursive function call passing headNode.next as param
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {

	static Node<ItemType>* currPtr = headPtr;
	// base Case
	if (currPtr == nullptr) {
		return 0;
	}
	// count this node plus the rest of the list
	else {
		return 1 + getCurrentSize340RecursiveNoHelper(currPtr->getNext());
	}
}

// this function uses an auziliary function to compute the size of the linked list
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& anEntry) const {
	return getFrequencyOf340RecursiveHelper(anEntry);
}

// recursive auxiliary function
// step 1: base case | check if headNode == null
// step 2: return recursive function call passing headNode.next as a param
// function will exit when base case is met ( node == null)
// 
// this is an auxiliary function used by the function above
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* currPtr, const ItemType& anEntry) const {

	// static variable retains updated value within this function
	// because it is still on the Runtime Stack for this functions
	// activation record
	static int count = 0;
	currPtr = headPtr;

	// base case 
	if (currPtr == nullptr) {
		return 0;
	}
	//match found
	else if (anEntry == currPtr->getItem()) {
		count++;
	}
	//recursive call
	else {
		return count + getFrequencyOf340RecursiveNoHelper(currPtr->getNext());
	}
}


// IMMEDIATE RECURSION
// step 1: initialize count = 0 to track frequency

// step 2: traverse linked list and increment count when match is found
// step 3: return count
template<typename ItemType> 
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& anEntry) const {

	// static variable retains updated value within this function
	// because it is still on the Runtime Stack for this functions
	// activation record
	static int count = 0; 
	Node<ItemType>* currPtr = LinkedBag::headPtr;
	
	// base case 
	if (currPtr == nullptr) {
		return 0;
	}
	//match found
	else if (anEntry == currPtr->getItem()) {
		count++;
	}
	//recursive call
	else {
		return count + getFrequencyOf340RecursiveNoHelper(currPtr->getNext());
	}
}

template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {

}
