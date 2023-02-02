class UnweightedGraph {
	public:
	long long nodes; // # of nodes
	long long edges; // # of edges
	bool undirected;
	vector<vector<long long> > adj; // adjacency neighbor vector
	vector<long long> visited; // visited nodes

	UnweightedGraph(long long nodes, long long edges, bool undirected) {
		this->nodes = nodes;
		this->edges = edges;
		this->undirected = undirected;
		adj = vector<vector<long long> >(nodes);
		visited = vector<long long>(nodes, false);
	}

	void init_adj() {
		f0r(i, edges) {
			ll n1, n2; // n1 for node1
			cin >> n1 >> n2;
			adj[n1 - 1].pb(n2 - 1);
			if(undirected) {
				adj[n2 - 1].pb(n1 - 1);
			}
		}
	}
};