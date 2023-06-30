// 0-indexed で使えます
template <typename T>
struct FenwickTreeRange {
    int n;             // 要素数
    V<T> bit[2];  // データの格納先
    FenwickTreeRange(int n_) { init(n_); }
    void init(int n_) {
        n = n_ + 1;
        for (int p = 0; p < 2; p++) bit[p].assign(n, 0);
    }

    // add(l,r,x): [l,r) に x を加算
    void add(int l, int r, T x) {
        l++;
        r++;
        add_sub(0, l, -x * (l - 1));
        add_sub(0, r, x * (r - 1));
        add_sub(1, l, x);
        add_sub(1, r, -x);
    }

    // sum(i): a_1 + a_2 + ... + a_i を計算
    T sum(int i) {
        i++;
        return sum_sub(0, i) + sum_sub(1, i) * i;
    }

    // [l,r) の区間和を取得
    T query(int l, int r) {
        l++;
        r++;
        return query_sub(r - 1) - query_sub(l - 1);
    }

   private:
    void add_sub(int p, int i, T x) {
        for (int idx = i; idx < n; idx += (idx & -idx)) {
            bit[p][idx] += x;
        }
    }

    T sum_sub(int p, int i) {
        T s(0);
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[p][idx];
        }
        return s;
    }

    T query_sub(int i) { return sum_sub(0, i) + sum_sub(1, i) * i; }
};