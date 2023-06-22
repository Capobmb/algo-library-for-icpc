struct DfsBfsTree {
    vector<vector<int>> edges;
    int n;
    DfsBfsTree(vector<vector<int>> &edges_) : edges(edges_), n(edges_.size()) {}
 
    void dfs_impl(int cur, vector<bool> &seen, vector<pair<int, int>> &output, 
    const vector<vector<int>> &edges) {
        for (auto& nxt : edges[cur]) {
            if (!seen[nxt]) {
                seen[nxt] = true;
                output.push_back({cur, nxt});
                dfs_impl(nxt, seen, output, edges);
            }
        }
    }
 
    void bfs_impl(int cur, vector<bool> &seen, vector<pair<int, int>> &output, 
    const vector<vector<int>> &edges) {
        queue<int> que;
        que.push(cur);
        seen[cur] = true;
        while (que.size()) {
            int now = que.front();
            que.pop();
            for (auto& nxt : edges[now]) {
                if (!seen[nxt]) {
                    seen[nxt] = true;
                    output.push_back({now, nxt});
                    que.push(nxt);
                }
            }
        }
    }

    // dfs 木を (現頂点, 次頂点) の pair で表現
    vector<pair<int, int>> dfs(int start) {
        vector<bool> seen(n);
        vector<pair<int, int>> res;
        seen[start] = true;
        dfs_impl(start, seen, res, edges);
        return res;
    }

    // bfs 木を (現頂点, 次頂点) の pair で表現
    vector<pair<int, int>> bfs(int start) {
        vector<bool> seen(n);
        vector<pair<int, int>> res;
        bfs_impl(start, seen, res, edges);
        return res;
    }
};