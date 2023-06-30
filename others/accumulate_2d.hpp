template <typename T>
struct Accumulate2D {
    int h, w;
    V<V<T>> accum;

    void init(V<V<T>>& _field) {
        h = _field.size();
        w = _field[0].size();
        accum.resize(h + 1, V<T>(w + 1, 0));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                accum[i + 1][j + 1] +=
                    accum[i + 1][j] + accum[i][j + 1] - accum[i][j] + _field[i][j];
            }
        }
    }

    /// @brief sum of range : [ i1, i2 ), [ j1, j2 )の範囲にある和を求める
    T query(int i1, int i2, int j1, int j2) {
        return accum[i2][j2] - accum[i1][j2] - accum[i2][j1] + accum[i1][j1];
    }
};