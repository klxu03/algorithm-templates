    // note that starting_node is unnecessary since indegree 0
    // create an indegree vector 
    void toposort(long long starting_node) {
        deque<long long> dq;
        dq.push_back(starting_node);

        for (int i = 0; i < nodes; i++) {
            if (i == starting_node) continue;

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