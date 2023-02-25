// Scuffed PQ so I can iterate through a pq
// Right after declare the PQ right the line below with this pasted in template above WeightedGraph
// vector<pair<ll, int>> &scuffed_pq = Container(pq);
template <class T, class S, class C>
S& Container(priority_queue<T, S, C>& q) {
    struct HackedQueue : private priority_queue<T, S, C> {
        static S& Container(priority_queue<T, S, C>& q) {
            return q.*&HackedQueue::c;
        }
    };
    return HackedQueue::Container(q);
}

class WeightedGraph {
    public:
    int nodes; // # of nodes
    int edges; // # of edges
    bool undirected;
    vector<vector<pair<int, int>>> adj; // adjacency neighbor vector
    // pair<first, second> = adj[5][0] where first is node 5's 1st neighbors pointed to node, and second is the cost
    vector<ll> dist; // distance to get to this node
    vector<int> prev;

    WeightedGraph(int _nodes, int _edges, bool _undirected) {
        nodes = _nodes;
        edges = _edges;
        undirected = _undirected;
        adj = vector<vector<pair<int, int>>>(_nodes);
        dist = vector<ll>(_nodes, LLONG_MAX);
        prev = vector<int>(_nodes, -1);
    }

    // Priority queues are sus and can't pass objects or lambda functions as comparator
    // This is how you get around it
    // auto comp = [](pair<ll, int>&a, pair<ll, int>&b) {
    //     return a.f > b.f;
    // };
    // // Priority queue where first is distance and second is the node you reach there with that distance
    // priority_queue<pair<ll, int>, vector<pair<ll, int>>, decltype(comp)> pq(comp);
    void dijkstra(int src) {
        fill(dist.begin(), dist.end(), LLONG_MAX);

        // Priority queue where first is distance and second is the node you reach there with that distance
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        dist[src] = 0;
        pq.push({0, src});

        while(pq.size()) { // not 0
            ll curr_dist; int node;
            tie(curr_dist, node) = pq.top();
            pq.pop();

            if (curr_dist > dist[node]) continue;
            for(pair<int, int> i : adj[node]) {
                // If we can reach neighboring node in shorter distance
                if (curr_dist + i.s < dist[i.f]) {
                    // Update new distance to reach this node
                    dist[i.f] = curr_dist + i.s;
                    prev[i.f] = node;

                    pq.push({dist[i.f], i.f});
                }
            }
        }
    }
};