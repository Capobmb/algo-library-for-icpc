template<typename T> vector<vector<T>> rotate_clockwise(vector<vector<T>> g) {
    int n = g.size();
    int m = g[0].size();
    vector<vector<T>> res(m, vector<T>(n));
    rep(i, 0, n) rep(j, 0, m) res[j][n - i - 1] = g[i][j];
    return res;
}