// lab2.cpp: определяет точку входа для приложения.
//

#include "linked_list_class.h"

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	cout << "Lab 2 Tests" << endl << "----------------------" << endl;

	cout << "Circular Linked List Tests" << endl << "----------------------" << endl << endl;

	CircularLinkedList<int> list1(3);
	CircularLinkedList<float> list2(3);
	CircularLinkedList<double> list3(3);
	CircularLinkedList<bool> list4(3);
	cout << "random int list: " << list1 << endl;
	cout << "random float list: " << list2 << endl;
	cout << "random double list: " << list3 << endl;
	cout << "random bool list: " << list4 << endl << "----------------------" << endl << endl;

	CircularLinkedList<int> list5(list1);
	cout << "copy constructor: " << list5 << endl;

	CircularLinkedList<int> list6;
	list6 = list1;
	cout << "equality operator: " << list5 << endl << "----------------------" << endl << endl;

	list1.push_tail(100000000);
	cout << "push_tail: " << list1 << endl;

	list1.pop_tail();
	cout << "pop_tail: " << list1 << endl;

	list1.push_head(100000000);
	cout << "push_head: " << list1 << endl;

	list1.pop_head();
	cout << "pop_head: " << list1 << endl;

	list6.push_tail(list1);
	cout << "push_tail list: " << list6 << endl;

	list6.push_tail(list1);
	cout << "push_tail list: " << list6 << endl;

	list6.push_head(list1);
	cout << "push_head list: " << list6 << endl << "----------------------" << endl << endl;

	CircularLinkedList<bool> list7(10);
	cout << "list7: " << list7 << endl;
	list7.delete_node(true);
	cout << "delete_node in list7 for true: " << list7 << endl;

	list6.delete_node(41);
	cout << "delete_node in list6 for 41: " << list6 << endl;


	cout << "operator [] read: " << list1[0] << endl;
	list1[0] = 100000000;
	cout << "operator [] write: " << list1[0] << endl;

	cout << "list1.size(): " << list1.size() << endl;


	return 0;
}
