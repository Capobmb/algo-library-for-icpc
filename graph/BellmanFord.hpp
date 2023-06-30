#include <bits/stdc++.h>

/*
  verified : 
  https://atcoder.jp/contests/abc264/tasks/abc264_g
  https://atcoder.jp/contests/abc264/submissions/34017676
*/

struct Edge {
    int to;
    ll cost;
    Edge(int _to, ll _cost) : to(_to), cost(_cost) {}
};
std::ostream& operator<<(std::ostream& os, Edge edge) {
    return os << edge.to << ' ' << edge.cost;
}
V<ll> bellman_ford(V<V<Edge>> edges, int start) {
    const int n = edges.size();
    assert(0 < n);
    V<ll> d(n, (1LL<<62) - 1);
    d[start] = 0LL;

    for(int i = 0; i < n; ++i) {
        for(int from = 0; from < n; ++from) {
            for(const auto& [to, cost] : edges[from]) {
                if(d[from] + cost < d[to]) {
                    d[to] = d[from] + cost;
                    if(i == n - 1) {
                        return V<ll>{};
                    }
                }
            }
        }
    }
    return d;
}