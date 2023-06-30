// 経路圧縮(root) + Union-by-Size (merge)
/**
 * @brief Union-Find
 */
struct UnionFind {
    /**
     * @brief Construct a new Union Find object
     * 
     * @param n vertex number
     */
    UnionFind(int n) : parent(n), size(n, 1), edge(n, 0), comps(n) {
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    /**
     * @brief Get the root of X. Path Compression.
     */
    int root(int x) {
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }
    /**
     * @brief Merge x and y. Merge Tech.
     * @return Whether the merge was conducted
     */
    bool merge(int x, int y) {
        int rx = root(x), ry = root(y);
        if(rx == ry) {
            ++edge[rx];
            return false;
        }
        if(size[rx] < size[ry]) std::swap(rx,ry);

        size[rx] += size[ry];
        edge[rx] += edge[ry] + 1;
        parent[ry] = rx;
        --comps;

        return true;
    }
    /**
     * @return Wheter x and y is in the same connected component
     */
    bool is_same(int x, int y) { return root(x) == root(y); }
    /**
     * @return Number of vertices in the connected component x belongs to
     */
    int vertices(int x) { return size[root(x)]; }
    /**
     * @return Number of edges in the connected component x belongs to
     */
    int edges(int x) {return edge[root(x)]; }
    /**
     * @return Number of all connected components
     */
    int components() const { return comps; }
    /**
     * @return V<V<int>> : List of connected components each of which contains vertex
     */
    V<V<int>> list_components() {
        int n = parent.size();
        V<int> root_buf(n);
        for(int i = 0; i < n; i++) root_buf[i] = root(i);
        V<V<int>> result;
        for(int i = 0; i < n; i++) result[root_buf[i]].push_back(i);

        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const V<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

private :
    V<int> parent, size, edge;
    int comps;
};