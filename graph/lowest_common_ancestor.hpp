struct LowestCommonAncestor {
    // parent[k][v] := v の 2^k 個先の親
    V<V<int>> parent;
    // dist[i] := 根から i までの距離
    V<int> dist;

    LowestCommonAncestor(const V<V<int>> &edges, int root=0) {
        init(edges, root);
    }

    /*
        前処理
        O(N log N)
    */
    void init(const V<V<int>> &edges, int root=0) {
        int vertex_size = (int)edges.size();
        int log_vertex_size = 1;
        while ((1 << log_vertex_size) < vertex_size) log_vertex_size++;
        parent.assign(log_vertex_size, V<int>(vertex_size, -1));
        dist.assign(vertex_size, -1);
        parent_init(edges, -1, root);
        dist_from_root(edges, -1, root, 0);
        // doubling
        for (int k = 0; k + 1 < log_vertex_size; k++) {
            for (int v = 0; v < vertex_size; v++) {
                if (parent[k][v] < 0) parent[k + 1][v] = -1;
                else parent[k + 1][v] = parent[k][parent[k][v]];
            }
        }
    }

    void parent_init(const V<V<int>> &edges, int pre, int cur) {
        parent[0][cur] = pre;
        for (auto& nxt : edges[cur]) {
            if (nxt != pre) parent_init(edges, cur, nxt);
        }
    }

    void dist_from_root(const V<V<int>> &edges, int pre, int cur, int dist_from_root_to_cur) {
        dist[cur] = dist_from_root_to_cur;
        for (auto& nxt : edges[cur]) {
            if (nxt != pre) 
                dist_from_root(edges, cur, nxt, dist_from_root_to_cur + 1);
        }
    }

    /* 
        頂点 u, v の LCA を求める
        O(log N)
     */
    int query(int u, int v) {
        // u : 深い方の頂点
        if (dist[u] < dist[v]) swap(u, v);
        int log_vertex_size = (int)parent.size();
        // LCA までの距離を小さいほうに合わせる
        for (int k = 0; k < log_vertex_size; k++) {
            if (((dist[u] - dist[v]) >> k) & 1) u = parent[k][u];
        }
        // LCA を二分探索で求める
        if (u == v) return u;
        for (int k = log_vertex_size - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    /*
        頂点 u, v 間の距離を求める
        O(log N)
    */
    int get_dist(int u, int v) {
        return dist[u] + dist[v] - 2 * dist[query(u, v)];
    }

    /*
        頂点 u, v を結ぶパス上に頂点 a が存在するかどうかを求める
        O(log N)
    */
    int is_on_path(int u, int v, int a) {
        return get_dist(u, a) + get_dist(a, v) == get_dist(u, v);
    }
};