template <typename T>
struct Edge {
    int to;
    T cost;
};

template <typename T>
pair<T, int> dfs_for_tree_diameter(const vector<vector<Edge<T>>> &edges, int cur, int pre) {
    pair<T, int> res = make_pair((T)0, cur);
    for (auto &[nxt, cost] : edges[cur]) {
        if (pre != nxt) {
            pair<T, int> nxt_pair = dfs_for_tree_diameter<T>(edges, nxt, cur);
            nxt_pair.first += cost;
            res = max(res, nxt_pair);
        }
    }
    return res;
}
template <typename T>
tuple<int, int, T> tree_diameter(const vector<vector<Edge<T>>> &edges) {
    pair<T, int> v1 = dfs_for_tree_diameter<T>(edges, 0, -1);
    pair<T, int> v2 = dfs_for_tree_diameter<T>(edges, v1.second, -1);
    return make_tuple(v1.second, v2.second, v2.first);
}