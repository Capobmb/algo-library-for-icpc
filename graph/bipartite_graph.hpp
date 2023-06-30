struct UnionFind {
    V<int> par, rank, siz;
    // V<bool> is_tree_impl;

    // initialization
    UnionFind(int N) : par(N, -1), rank(N, 0), siz(N, 1) 
    // , is_tree_impl(N, true) 
    {}

    int root(int x) {
        if (par[x] == -1) return x;
        return par[x] = root(par[x]);
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) {
            // is_tree_impl[rx] = false;
            return;
        }
        if (rank[rx] < rank[ry]) swap(rx, ry);
        // if (same(rx, ry) or !is_tree_impl[ry]) is_tree_impl[rx] = false;
        par[ry] = rx;
        if (rank[rx] == rank[ry]) rank[rx]++;
        siz[rx] += siz[ry];
    }

    int size(int x) {
        return siz[root(x)];
    }

    // bool is_tree(int x) {
    //     return is_tree_impl[root(x)];
    // }
};

struct BipartiteGraph : UnionFind {
    // https://ei1333.github.io/algorithm/union-find.html より
    // validation : https://atcoder.jp/contests/abc282/submissions/37365726

    V<int> color;
    int v;
    BipartiteGraph(int v_) : v(v_), color(v_ + v_, -1), UnionFind(v_ + v_) {}

    bool bipartite_graph_coloring() {
        // 隣接頂点を同じ色にするとき : unite(u, v); unite(u + N, v + N);
        // 隣接頂点を違う色にするとき : unite(u, v + N); unite(u + N, v);
        for (int i = 0; i < v; i++) {
            int a = root(i);
            int b = root(i + v);
            if (a == b) return false;
            if (color[a] < 0) {
                color[a] = 0; 
                color[b] = 1;
            }
        }
        return true;
    }

    bool get_color(int k) { return bool(color[root(k)]); }
};