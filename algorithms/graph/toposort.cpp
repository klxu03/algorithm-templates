    // note that starting_node is unnecessary since indegree 0
    // create an indegree vector 
    void toposort() {
        deque<long long> dq;

        for (int i = 0; i < nodes; i++) {
            if (indegree[i] == 0) {
                dq.pb(i);
            }
        }

        while(!dq.empty()) {
            long long current = dq.front();
            dq.pop_front();

            for (long long neighbor : adj[current]) {
                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    dq.push_back(neighbor);
                }
            }
        }
    }