vector<int> arr;
// leftmost element that is greater than or equal to val
int binary_search_leftmost(int val) {
	int l = 0; // left
	int r = n - 1; // right

	while (l < r) {
		int mid = l + (r - l)/2;

		if (arr[mid] >= val) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	// could instead just set r = n instead so its possible to assume value of n
	if (arr[l] < val) {
		l++; 
	}

	return l;
}

// rightmost element that is less than or equal to val
int binary_search_rightmost(int val) {
	int l = 0; // left
	int r = n - 1; // right
 
	while (l < r) {
		int mid = l + (r - l)/2;
 
		if (arr[mid] <= val) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}

	if (arr[l] > val) {
		l--;
	}
 
	return l;
}


int binary_search_greater(int val) {
	int l = 0; // left
	int r = n - 1; // right

	while (l < r) {
		int mid = l + (r - l)/2;

		if (arr[mid] > val) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	// could instead just set r = n instead so its possible to assume value of n
	if (arr[l] <= val) {
		l++; 
	}

	return l;
}

void solve() {
	cin >> n;
	arr = vector<int>(n);

	f0r(i, n) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	DEBUG(arr);

	cin >> q;
	f0r(i, q) {
		int inp_l, inp_r;
		cin >> inp_l >> inp_r;
		int l = binary_search_leftmost(inp_l);
		int r = binary_search_greater(inp_r);

		DEBUG(l, r);
		cout << r - l << " ";
	}
	cout << endl;
}