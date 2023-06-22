/* 
    2次元 vector : A の周囲 4 辺に番兵を設定します
    縦横のサイズを +2 します 
*/
template<typename T>
vector<vector<T>> make_sentinel(vector<vector<T>> &A, int& H, int& W, T sentinel) {
    vector<vector<T>> res(H + 2);
    for (int j = 0; j < W + 2; j++) {
        res[0].push_back(sentinel);
    }
    for (int i = 0; i < H; i++) {
        res[i + 1].push_back(sentinel);
        for (int j = 0; j < W; j++) {
            res[i + 1].push_back(A[i][j]);
        }
        res[i + 1].push_back(sentinel);
    }
    for (int j = 0; j < W + 2; j++) {
        res[H + 1].push_back(sentinel);
    }
    // H += 2;
    // W += 2;
    return res;
}