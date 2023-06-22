// vector<int> edgenum(MAX_N, -1);
struct Edge {
    int to;
    ll cost;
    // int id;
};

using Graph = vector<vector<Edge> >;

using pli = pair<long long, int>;
void dijkstra(const Graph &G, int s, vector<ll> &dis) {
    int N = G.size();
    dis.resize(N, INFL);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dis[s] = 0;
    pq.emplace(dis[s], s);

    while (!pq.empty()) {
        pli p = pq.top();
        pq.pop();
        long long cd = p.first;
        int cv = p.second;

        if (dis[cv] != cd) {
            continue;
        }

        for (auto &e : G[cv]) {
            if (dis[e.to] > dis[cv] + e.cost) { // 最短距離候補
                dis[e.to] = dis[cv] + e.cost;
                pq.push({dis[e.to], e.to});
                // edgenum[e.to] = e.id;
            }
        }
    }
}