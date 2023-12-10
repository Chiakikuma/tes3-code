#include "binary_search_2.h"
#include <iostream>
using namespace std;

int main () {
	int array[] = { 2, 3, 5, 7 };
	int size = sizeof(array) / sizeof(int);
	for (int val = 0; val < 10; val++)
		cout << val << ": " << binary_search(array, size, val) << endl;
	system("pause");
	return 0;
}
