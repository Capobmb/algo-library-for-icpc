struct UnionFind2D {
    vector<vector<pair<int, int>>> par;
    vector<vector<int>> rank, siz;

    UnionFind2D(int H, int W) : 
        par(H, vector<pair<int, int>>(W, {-1, -1})), 
        rank(H, vector<int>(W)), siz(H, vector<int>(W)) {}

    pair<int, int> root(int x, int y) {
        if (par[x][y] == make_pair(-1, -1)) {
            return {x, y};
        }
        return par[x][y] = root(par[x][y].first, par[x][y].second);
    }

    void unite(int cx, int cy, int nx, int ny) {
        pair<int, int> rc = root(cx, cy);
        pair<int, int> rn = root(nx, ny);
        if (rc == rn) {
            return;
        }
        if (rank[rc.first][rc.second] < rank[rn.first][rn.second]) {
            swap(rc, rn);
        }
        par[rn.first][rn.second] = rc;
        if (rank[rc.first][rc.second] == rank[rn.first][rn.second]) {
            rank[rc.first][rc.second]++;
        }
        siz[rc.first][rc.second] += siz[rn.first][rn.second];
    }

    bool same(int cx, int cy, int nx, int ny) {
        return root(cx, cy) == root(nx, ny);
    }

    int size(int cx, int cy) {
        return siz[root(cx, cy).first][root(cx, cy).second];
    }
};