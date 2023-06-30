V<int> topological_sort(V<V<int> > &G, V<int> &indegree) {
    // 入力の段階で indegree をいじっておくことを忘れない！
    V<int> res;
    int N = G.size(); // 頂点数
    queue<int> que;
    rep(i, N) {
        if (indegree[i] == 0) que.push(i);
    }
    while (!que.empty()) {
        int v = que.front(); que.pop();
        res.push_back(v);
        fore (vv, G[v]) {
            indegree[vv]--;
            if (indegree[vv] == 0) que.push(vv);
        }
    }
    return res;
}