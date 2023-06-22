struct UnionFind {
    vector<int> par, rank, siz;
    // vector<bool> is_tree_impl;

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