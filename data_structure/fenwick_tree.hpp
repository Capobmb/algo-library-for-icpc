template <typename T>
struct FenwickTree {
    const T INF = numeric_limits<T>::max();
    int N; // 元の配列のサイズ
    int n;
    V<T> dat;
    FenwickTree(int n_) : N(n_), n(), dat(n_ * 4, 0) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }

    // a[i] に x を加算
    void add(int i, T x) {
        assert(0 <= i && i < N);
        i++;
        while (i <= n) {
            dat[i] += x;
            i += i & -i;
        }
    }

    // a[0, i) (半開区間) の和 (O(log N))
    T sum(int i) {
        assert(0 <= i && i <= N);
        T s = 0;
        while (i > 0) {
            s += dat[i];
            i -= i & -i;
        }
        return s;
    }

    // a_l + ... + a_{r-1}
    
    // a [l, r) の和 (半開区間) O(log N)
    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= N);
        return sum(r) - sum(l);
    }

};