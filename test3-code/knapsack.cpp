#include "knapsack.h"
#include <iostream>
using namespace std;

void solve (list<Item>& items, list<Item>::iterator it,
		Knapsack& cur, Knapsack& best) {
	// If reach bottom of search space, evaluate the solution.
	if (it == items.end()) {
		//cout << cur << endl; // output current solution being evaluated
		if (cur.value() > best.value())
			best = cur;
	}
	else {
		// it points to an item in the item list
		list<Item>::iterator it_next = it;
		it_next++;
		// Put item into cur Knapsack, expand solution to next item 
		try {
			cur.add(*it);
			solve(items, it_next, cur, best);
			// Remove item from cur Knapsack, exapand solution to next item
			cur.remove(*it);
		}
		catch (int error) { }
		solve(items, it_next, cur, best);
	}
}

int main () {

	list<Item> items;
	items.push_back(Item(12, 4));
	items.push_back(Item(2, 2));
	items.push_back(Item(1, 2));
	items.push_back(Item(1, 1));
	items.push_back(Item(4, 10));

	cout << "Candidate items: ";
	for (auto item: items)
		cout << item;
	cout << endl;

	Knapsack knap(15); // solution
	Knapsack cur(15); // for finding a solution
	solve(items, items.begin(), cur, knap);

	cout << "Knapsack items: ";
	cout << knap << endl;

#ifdef _MSC_VER
	system("pause");
#endif

	return 0;
}
