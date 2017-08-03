#ifndef NODE_HPP_
#define NODE_HPP_
template<class dataType>
class Node {
	public:
		Node() {};
		~Node() {};
		dataType value;
		Node<dataType> * next;
		dataType at(size_t);
		Node<dataType> nodeAt(size_t);
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
		Node<dataType> * head;
		size_t length = 0;
		//functions
		size_t size();
		void push_forward(dataType);
		void push_back(dataType);
		void erase(size_t);
		void erase(size_t, size_t);
		dataType at(size_t);
	private:
		Node<dataType> * nodeAt(size_t);
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
