#include "Test.h"
#include "LinkedList.h"

void LinkedListTest()
{
	LinkedList<int> list;
	list.append(1);
	list.append(2);
	list.push(3);
	list.append(4);
	list.insert(0, 6);
	list.insert(5, 7);
	list.printList();
	list.pop(0);
	std::cout << list.size() << std::endl;
	list.printList();
	list.reverse();
	list.printList();
	std::cout << list.size() << std::endl;
	list.append(5);
	list.printList();
	list.del();
	list.printList();
	list.insert(0, 5);
	list.push(1);
	list.printList();
}