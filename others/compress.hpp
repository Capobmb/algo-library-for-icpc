/* compress
    X を座標圧縮して書き換える
    返り値: ソート済みの値(Xにどの値が存在するかを昇順に)
    計算量: O(n log n)
*/
template <typename T> V<T> compress(V<T>& X) {
    // ソートした結果を vals に
    V<T> vals = X;
    sort(vals.begin(), vals.end());
    // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    // 各要素ごとに二分探索で位置を求める
    for (int i = 0; i < (int)X.size(); i++) {
        X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
    }
    return vals;
}
/*
    a = {6, 1, 7, 1, 2}
    compress(a) = {1, 2, 6, 7}
    a = {2, 0, 3, 0, 1}
*/