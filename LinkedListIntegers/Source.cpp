#include <iostream>
#include <string>
#include "List.h"
using namespace std;

int main()
{
	List<int> listOfIntegers;

	int values;

	cout << "Enter elements into list to end input enter -1: ";
	cin >> values;

	while (values != -1)
	{
		listOfIntegers.insertAtBack(values);

		cout << "Enter elements into list to end input enter -1: ";
		cin >> values;

	}


	cout << "List before delete of even nodes:\n";
	listOfIntegers.print();

	if (!listOfIntegers.isEmpty())
	{
		listOfIntegers.deleteEvenNode();
		cout << "List after delete of even nodes:\n";
		listOfIntegers.print();

	}

}
