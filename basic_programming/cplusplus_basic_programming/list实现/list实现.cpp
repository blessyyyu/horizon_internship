#include <iostream>
#include "mylist.h"
int main()
{
	MyList list;
	
	list.append({ 1 ,2, "abc", 3.5});
	list.print_vector();

	auto initalist = std::initializer_list<T>{ 1,2,3,3.5,"hello" };
	MyList list2(initalist);
	list2.print_vector();


	T var = 1023;
	MyList list3(var);
	list3.print_vector();
	return 0;
}

