struct UnionFind {
    // par[i] := parent of i
    V<int> par, rank, siz;

    // initialization
    UnionFind(int N) : par(N, -1), rank(N, 0), siz(N, 1) {}

    int root(int x) {
        if (par[x] == -1) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        /* unite the trees where x and y belong */
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]) swap(rx, ry);
        par[ry] = rx;
        if (rank[rx] == rank[ry]) rank[rx]++;
        siz[rx] += siz[ry];
    }

    bool same(int x, int y) {return root(x) == root(y);}
    int size(int x) {return siz[root(x)];}
};

struct Edge {
    int u; int v; ll cost;
};
bool comparefunc (const Edge &e1, const Edge &e2) {
    return e1.cost < e2.cost;
}

struct Kruskal {
    V<Edge> edges;
    int V;
    // initialization
    Kruskal(const V<Edge> &edges_, int V_) : edges(edges_), V(V_) { init(); }

    void init() {
        sort(edges.begin(), edges.end(), comparefunc);
        UnionFind UF(V);
        for (auto &e : edges) {
            if (!UF.same(e.u, e.v)) {
                UF.unite(e.u, e.v);
            }
        }
    }
};