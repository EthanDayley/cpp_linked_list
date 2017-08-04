#ifndef NODE_HPP_
#define NODE_HPP_
template<class dataType>
class Node {
	public:
		Node() {};
		~Node() {};
		dataType value;			//the value stored in the node
		Node<dataType> * next;   	//the next node in the linkedlist
};
#endif

#include <iostream>

#ifndef LLIST_HPP_
#define LLIST_HPP_
template<class dataType>
class LinkedList {
	public:
		LinkedList() {};
		~LinkedList() {};
		size_t size(); //gets the size of the linkedlist
		void push_forward(dataType); //adds an element to the begining of the list
		void push_back(dataType);    //adds an element to the end of the list
		void erase(size_t);          //erases an element at an index in the list
		void erase(size_t, size_t);  //erases all element in the range of indices
		void insert(dataType, size_t);//inserts an element at the given index
		void setIndex(dataType, size_t); //sets the node at the index with a value
		dataType at(size_t);	     //returns the value of the index
		dataType operator[] (size_t index) {
			return at(index);
		}
	private:
		Node<dataType> * nodeAt(size_t); //returns the node at the given index
		Node<dataType> * head;           //the beginning of the list
		size_t length = 0;               //the number of elements in the list
};

template<class dataType>
size_t LinkedList<dataType>::size() {
	return length;
}

template<class dataType>
void LinkedList<dataType>::push_forward(dataType newVal) {
	Node<dataType> * n = new Node<dataType>;
	n->value = newVal;
	if (length > 0) {
		n->next = head;
	}
	head = n;
	length++;
}

template<class dataType>
void LinkedList<dataType>::push_back(dataType newVal) {
	Node<dataType> * end = nodeAt(size()-1);
	Node<dataType> * n = new Node<dataType>;
	n->value = newVal;
	end->next = n;
	length++;
}

template<class dataType>
void LinkedList<dataType>::erase(size_t index) {
	if (index == 0) {
		Node<dataType> * deleteAble = head;
		head = nodeAt(1);
		delete deleteAble;
		length--;
		return;
	}
	Node<dataType> * changeNext = nodeAt(index-1);
	Node<dataType> * deleteAble = changeNext->next;
	changeNext->next = deleteAble->next;
	length--;
	delete deleteAble;
}

template<class dataType>
void LinkedList<dataType>::erase(size_t index1, size_t index2) {
	for (int i = index1; i <= index2; i++) {
		erase(index1);
	}
}
template<class dataType>
void LinkedList<dataType>::insert(dataType newVal, size_t index) {
	Node<dataType> * before = nodeAt(index-1);
	Node<dataType> * after = nodeAt(index);
	Node<dataType> * newNode = new Node<dataType>;
	newNode->value = newVal;
	before->next = newNode;
	newNode->next = after;
	length++;
}

template<class dataType>
void LinkedList<dataType>::setIndex(dataType newVal, size_t index) {
	Node<dataType> * n = nodeAt(index);
	n->value = newVal;
}

template<class dataType>
Node<dataType> * LinkedList<dataType>::nodeAt(size_t index) {
	Node<dataType> * curr = head;
	for (int i = 0; i < index; i++) {
		curr = curr->next;
	}
	return curr;
}

template<class dataType>
dataType LinkedList<dataType>::at(size_t index) {
	return nodeAt(index)->value;
}
#endif
