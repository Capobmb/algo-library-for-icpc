template <typename X>
struct SegTree {
    using FX = function<X(X, X)>; // X•X -> X となる関数の型
    int n;
    FX fx;
    FX update_func;
    const X ex;
    vector<X> dat;
    // SegTree<X>(n,fx,ex): モノイド(集合X, 二項演算fx, 単位元ex)についてサイズnで構築
    SegTree(int n_, FX fx_, X ex_) : n(), fx(fx_), ex(ex_), dat(n_ * 4, ex_) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }

    // set(int i, X x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
    void set(int i, X x) { dat[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }

    // update(i,x): i 番目の要素を x に更新。O(log(n))
    void update(int i, X x) {
        i += n - 1;
        /* 一点更新とか加算とかに応じて dat[i] に x をどう作用させるか変える */
        dat[i] += x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }

    // query(a,b): [a,b) 全てにfxを作用させた値を取得。O(log(n))
    X query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    X query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return ex;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            X value_left = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X value_right = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(value_left, value_right);
        }
    }
};