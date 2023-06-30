template<typename T> V<V<T>> rotate_clockwise(V<V<T>> g) {
    int n = g.size();
    int m = g[0].size();
    V<V<T>> res(m, V<T>(n));
    rep(i, 0, n) rep(j, 0, m) res[j][n - i - 1] = g[i][j];
    return res;
}