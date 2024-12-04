#pragma once 
#include <iostream>
#include <random>
#include <cmath>

using namespace std;


template <typename T>
struct Node {
    T value;
    Node* next;

    Node(const T& value, Node<T>* next = nullptr) : value(value), next(next) {}
};


template <typename T>
class CircularLinkedList {
private:
    Node<T>* _tail;

public:
    Node<T>* get_head() const {
        return _tail->next;
    }

    CircularLinkedList() : _tail(nullptr) {}

	CircularLinkedList(const CircularLinkedList& list) : _tail(nullptr) {
		if (list.empty()) {
			return;
		}

		Node<T>* ptr = list._tail->next;
		do {
			push_tail(ptr->value);
			ptr = ptr->next;
		} while (ptr != list._tail->next);
	} 

	CircularLinkedList(const size_t size) {};

	CircularLinkedList<T>& operator=(const CircularLinkedList<T>& lst) {
        if (this != &lst) {
            clear();
            if (!lst.empty()) {
                Node<T>* current = lst._tail->next;
                do {
                    push_tail(current->value);
                    current = current->next;
                } while (current != lst._tail->next);
            }
        }
        return *this;
	}

	~CircularLinkedList() {
        clear();
	}


	bool empty() const {
		return _tail == nullptr;
	}

    void clear() {
        if (empty()) {
            return;
        }

        Node<T>* current = _tail->next; 
        Node<T>* nextNode = nullptr;

        while (current != _tail) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }

        delete current;

        _tail = nullptr;
    }

    void push_tail(const T& value) {
        Node<T>* newNode = new Node<T>(value, nullptr);
        if (empty()) {
            _tail = newNode;
            _tail->next = _tail;
        }
        else {
            newNode->next = _tail->next;
            _tail->next = newNode;
            _tail = newNode;
        }
    }

    void push_tail(const CircularLinkedList<T>& list) {
        if (list.empty())
            return; 

        Node<T>* ptr = list._tail->next;
        do {
            push_tail(ptr->value);
            ptr = ptr->next;
        } while (ptr != list._tail->next);
    }

    void push_head(const T value) {
        Node<T>* new_node = new Node<T>(value, nullptr);

        if (empty()) {
            _tail = new_node;
            _tail->next = _tail;
        }
        else {
            new_node->next = _tail->next;
            _tail->next = new_node;
        }
    }

    void push_head(const CircularLinkedList<T>& list) {
        if (list.empty())
            return;

        Node<T>* ptr = list._tail;
        Node<T>* previous_ptr = list._tail;
        do {
            push_head(ptr->value);
            while (ptr->next != previous_ptr) {
                ptr = ptr->next;
            }
            previous_ptr = ptr;
        } while (ptr != list._tail);
    }

    void pop_head() {
        if (empty()) {
            throw out_of_range("Linked list is empty");
        }
        if (this->_tail == this->_tail->next) {
            delete _tail;
            _tail = nullptr;
            return;
        }
        Node<T>* ptr = _tail->next;
        _tail->next = ptr->next;
        delete ptr;

    }

    void pop_tail() {
        if (empty()) {
            throw out_of_range("Linked list is empty");
        }
        if (this->_tail == this->_tail->next) {
            delete _tail;
            _tail = nullptr;
            return;
        }
        Node<T>* ptr = _tail->next;
        while (ptr->next != _tail) {
            ptr = ptr->next;
        }
        ptr->next = _tail->next;
        delete _tail;
        _tail = ptr;
    }

    void delete_node(const T& value) {
        if (empty()) {
            return;
        }
        Node<T>* ptr = _tail->next;
        Node<T>* previous_ptr = _tail;
        

        do {
            if (ptr->value == value) {
                Node<T>* to_delete = ptr;
                ptr = ptr->next;
                previous_ptr->next = ptr;

            }
            else {
                previous_ptr = ptr;
                ptr = ptr->next;
            }
        } while (ptr != _tail);

        if (_tail->value == value) {
            pop_tail();
        }

    }

    T operator[](size_t index) const {
        if (index < 0 || index >= this->size()) {
            throw out_of_range("Index is out of range");
        }
        Node<T>* ptr = _tail->next;
        for (int i = 0; i < index; i++) {
            ptr = ptr->next;
        }
        return ptr->value;
    }

    T& operator[](size_t index) {
        if (index < 0 || index >= this->size()) {
            throw out_of_range("Index is out of range");
        }
        Node<T>* ptr = _tail->next;
        for (int i = 0; i < index; i++) {
            ptr = ptr->next;
        }
        return ptr->value;
    }

    size_t size() const {
        Node<T>* ptr = _tail->next;
        size_t size = 0;
        if (empty()) {
            size = 0;
            return size;
        }
        do {
            ptr = ptr->next;
            size++;
        } while (ptr != _tail->next);
        return size;
    }

    template <typename T>
    friend void show_polynomial_list(const CircularLinkedList<T>& list);

    template <typename T>
    friend T calc_x(const CircularLinkedList<T>& list, const T x);
};

template <typename T>
ostream& operator<<(ostream& a, const CircularLinkedList<T>& list) {
    if (list.empty()) {
        a << "List is empty";
        return a;
    }

    Node<T>* ptr = list.get_head();
    Node<T>* start = ptr;

    do {
        a << ptr->value << " ";
        ptr = ptr->next;
    } while (ptr != start);

    return a;
}


template <>
CircularLinkedList<int>::CircularLinkedList(size_t size) : _tail(nullptr) {
    for (int i = 0; i < size; i++) {
        this->push_tail(rand());
    }
}

template <>
CircularLinkedList<bool>::CircularLinkedList(size_t size) : _tail(nullptr) {
    for (int i = 0; i < size; i++) {
        this->push_tail(rand() % 2);
    }
}

template <>
CircularLinkedList<float>::CircularLinkedList(size_t size) : _tail(nullptr) {
    for (int i = 0; i < size; i++) {
        this->push_tail(rand() + 0.00001 * rand());
    }
}

template <>
CircularLinkedList<double>::CircularLinkedList(size_t size) : _tail(nullptr) {
    for (int i = 0; i < size; i++) {
        this->push_tail(rand() + 0.00001 * rand());
    }
}


template <typename T>
void show_polynomial_list(const CircularLinkedList<T>& list) {
    if (list.empty()) {
        throw out_of_range("Linked list is empty");
    }

    Node<T>* ptr = list._tail;
    Node<T>* previous_ptr = list._tail;
    size_t index = list.size() - 1;
    if (index == 0) {
        cout << list._tail->next->value;
        return;
    }
    do {
        if (ptr->value != 0) {
            cout << ptr->value << "x^" << index;
            if (index != 1) {
                cout << " + ";
            }
        }
        while (ptr->next != previous_ptr) {
            ptr = ptr->next;
        }
        previous_ptr = ptr;
        index--;
    } while (ptr != list._tail->next);
    if (list._tail->next->value != 0) {
        cout << " + " << list._tail->next->value;
    }
}

template <typename T>
T calc_x(const CircularLinkedList<T>& list, const T x) {
    T res = 0;
    Node<T>* ptr = list._tail;
    Node<T>* previous_ptr = list._tail;
    size_t index = list.size() - 1;
    if (index == 0) {
        return ptr->value;
    }
    do {
        res += ptr->value * pow(x, index);
        while (ptr->next != previous_ptr) {
            ptr = ptr->next;
        }
        previous_ptr = ptr;
        index--;
    } while (ptr != list._tail->next);
    res += list._tail->next->value;
    return res;
}

template <typename T>
void fixed_show_polynomial_list(const CircularLinkedList<T>& list) {
    if (list.empty()) {
        throw out_of_range("Linked list is empty");
    }

    size_t index = list.size() - 1;
    for (size_t i = 0; i < list.size(); i++) {
        T value = list[i];
        if (value != 0) {
            cout << value;
            if (index > 1) {
                cout << "x^" << index << " + ";
            }
            if (index == 1) {
                cout << "x" << endl;
            }
        }
        index--;
    }
}


template<typename T>
T fixed_calc_x(const CircularLinkedList<T>& list, const T x) {
    if (list.empty()) {
        throw out_of_range("Linked list is empty");
    }

    T result = 0;
    size_t index = list.size() - 1;
    for (size_t i = 0; i < list.size(); i++) {
        T value = list[i];
        result += value * pow(x, index);
        index--;
    }
    return result;
}