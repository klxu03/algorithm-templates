    void dfs(long long starting_node) {
        deque<long long> dq;
        dq.push_front(starting_node);

        while(!dq.empty()) {
            long long current = dq.front();
            visited[current] = true;

            if(adj[current].size() == 0) {
                dq.pop_front();
            }

            f0r(i, adj[current].size()) {
                long long neighbor = adj[current][i];
                if(visited[neighbor] == false) {
                    dq.push_front(neighbor);
                    break;
                } 
                /* If I've skipped through all and none of 
                the neighbors haven't been visited */
                if (i == adj[current].size() - 1) dq.pop_front();
            }
        }
    }