// lab2.cpp: определяет точку входа для приложения.
//

#include "linked_list_class.h"

using namespace std;

int main()
{
	//srand(static_cast<unsigned int>(time(nullptr)));
	srand(static_cast<unsigned int>(1));


	cout << "Lab 2 Tests" << endl << "----------------------" << endl;

	cout << "Circular Linked List Tests" << endl << "----------------------" << endl << endl;

	CircularLinkedList<int> list1(3);
	CircularLinkedList<float> list2(3);
	CircularLinkedList<double> list3(3);
	CircularLinkedList<bool> list4(3);
	cout << "random int list(list1): " << list1 << endl;
	cout << "random float list(list2): " << list2 << endl;
	cout << "random double list(list3): " << list3 << endl;
	cout << "random bool list(list4): " << list4 << endl << "----------------------" << endl << endl;

	CircularLinkedList<int> list5(list1);
	cout << "copy constructor(list5(list1)): " << list5 << endl;

	CircularLinkedList<int> list6;
	list6 = list1;
	cout << "equality operator(list6 = list1): " << list6 << endl << "----------------------" << endl << endl;

	list1.push_tail(100000000);
	cout << "list1.push_tail: " << list1 << endl;

	list1.pop_tail();
	cout << "list1.pop_tail: " << list1 << endl;

	list1.push_head(100000000);
	cout << "list1.push_head: " << list1 << endl;

	list1.pop_head();
	cout << "list1.pop_head: " << list1 << endl;

	list6.push_tail(list1);
	cout << "list6.push_tail(list1): " << list6 << endl;

	list6.push_tail(list1);
	cout << "list6.push_tail(list1): " << list6 << endl;

	list6.push_head(list1);
	cout << "list6.push_head(list1): " << list6 << endl << "----------------------" << endl << endl;

	CircularLinkedList<bool> list7(10);
	cout << "list7(10): " << list7 << endl;

	list7.delete_node(true);

	cout << "delete_node in list7 for true: " << list7 << endl;
	list6.push_head(41);
	list6.delete_node(41);
	cout << "delete_node in list6 for 41: " << list6 << endl;
	list6.clear();
	cout << list6 << endl;
	list6.push_head(41);
	cout << list6 << endl;
	list6.delete_node(41);
	cout << list6 << endl;
	cout << "operator [] read(list1[0]): " << list1[0] << endl;
	list1[0] = 10000;
	cout << "operator [] write(list1[0] = 10000): " << list1[0] << endl;

	cout << "list1.size(): " << list1.size() << endl;


	return 0;
}
