#ifndef BINARY_SEARCH
#define BINARY_SEARCH

// Search for x in sorted array a, returning index of x, or -1 if not found
template <typename Comparable>
int binary_search (Comparable a[], int n, const Comparable& x) {

	int low = 0; // Low end of search range, initially first element
	int high = n - 1; // High end, initially last element

	while (low <= high) {
		int mid = (low + high) / 2; // Find midpoint
		if (a[mid] < x)
			low = mid + 1; // Adjust low end
		else if (a[mid] > x)
			high = mid - 1; // Adjust high end
		else
			return mid; // Found target, done.
	}

	return -1; // Not found.
}

#endif
