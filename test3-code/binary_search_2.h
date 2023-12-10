#ifndef BINARY_SEARCH
#define BINARY_SEARCH

// Search for x in sorted array a, within index range low to high, returning
//	index of x, or -1 if not found
template <typename Comparable>
int binary_search (Comparable a[], int low, int high, const Comparable& x) {
	if (low > high)
		return -1; // Not found

	int mid = (low + high) / 2; // Find midpoint
	if (a[mid] == x)
		return mid; // Found target, done.

	return x < a[mid] ?
		binary_search(a, low, mid - 1, x) :
		binary_search(a, mid + 1, high, x);
}

// Search for x in sorted array a, returning index of x, or -1 if not found
template <typename Comparable>
int binary_search (Comparable a[], int n, const Comparable& x) {
	return binary_search(a, 0, n - 1, x);
}

#endif
