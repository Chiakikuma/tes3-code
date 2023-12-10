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
	int n1 = 1;
	int n2 = 1;
	int n3;
	for (int i = 3; i <= n; i++) {
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
	}
	return n3;
}
