template <typename T>
struct WeightedUnionFind {
    // diff_weight[i] := i と par[i] との差分
    vector<int> par, rank;
    vector<long long> diff_weight;

    WeightedUnionFind(int N) {
        par.assign(N, -1); 
        rank.assign(N, 0); 
        diff_weight.assign(N, 0);
    }

    int root(int x) {
        if (par[x] == -1) return x;
        int r = root(par[x]);
        diff_weight[x] += diff_weight[par[x]]; // 親をさかのぼると同時に diff_weight の累積和を取る
        return par[x] = r;
    }

    long long weight(int x) {
        root(x);
        return diff_weight[x];
    }

    void unite(int x, int y, long long z) {
        z += weight(x) - weight(y);
        int rx = root(x), ry = root(y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]) {
            swap(rx, ry);
            z *= -1;
        }
        if (rank[rx] == rank[ry]) rank[rx]++;
        par[ry] = rx;
        diff_weight[ry] = z;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
};