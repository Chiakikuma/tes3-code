#include <iostream>
using namespace std;

unsigned int fibonacci (unsigned int n);

int main () {
	int n;
	cout << "Enter n: ";
	cin >> n;
	cout << fibonacci(n) << endl;
	return 0;
}

unsigned int fibonacci (unsigned int n) {
	if (n < 3)
		return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}
