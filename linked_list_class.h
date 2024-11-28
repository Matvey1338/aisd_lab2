#pragma once 
#include <iostream>


using namespace std;


template <typename T>
struct Node {
    T value;
    Node* next;

    Node(const T& value, Node<T>* next = nullptr) : value(value), next(nullptr) {}
};

template <typename T>
class CircularLinkedList {
private:
    Node<T>* _head;

public:

	Node<T>* get_head() const {
		return _head;
	}

	LinkedList() : _head(nullptr) {}

	LinkedList(const LinkedList& list) : _head(nullptr) {
		auto ptr = list._head;
		while (ptr) {
			push_tail(ptr->value);
			ptr = ptr->next;
		}
	}
};