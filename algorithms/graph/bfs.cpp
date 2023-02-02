    void bfs(long long starting_node) {
        deque<long long> dq;
        dq.push_back(starting_node);
        visited[starting_node] = true;

        // dist array for each node distance from starting node
        vector<long long> dist(nodes); 

        while(!dq.empty()) {
            long long current = dq.front();
            dq.pop_front();

            for (long long neighbor : adj[current]) {
                if (visited[neighbor] == false) {
                    visited[neighbor] = true;
                    dq.push_back(neighbor);
                    dist[neighbor] = dist[current] + 1;
                }
            }
        }
    }