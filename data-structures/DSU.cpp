class DSU {
    public:
    vector<int> c; // c for components

    DSU() {}

    void init(int n) {
        c = vector<int>(n, -1);
    }

    // get representive component (uses path compression)
	int get(int x) { 
        return c[x] < 0 ? x : c[x] = get(c[x]); 
    }

    bool same_set(int a, int b) { 
        return get(a) == get(b); 
    }

    int size(int x) { 
        return -c[get(x)]; 
    }

    bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false; // same group
		if (c[x] > c[y]) swap(x, y); // if c[x] is less negative, or greater than c[y]
		
        c[x] += c[y]; 
        c[y] = x;
		return true;
	}
};