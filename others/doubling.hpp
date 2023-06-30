struct Doubling {
    int N;
    V<int> nxt;
    V<V<int>> doubling;
    const int logK = 62;
    
    Doubling(const V<int>& nxt_) : 
        nxt(nxt_), N(nxt_.size()) 
    {
        doubling.assign(logK, V<int>(N));
        init();
    }

    void init() {
        // 初期化 O(N logK)
        for (int i = 0; i < N; i++) {
            doubling[0][i] = nxt[i];
        }
        for (int k = 0; k < logK - 1; k++) {
            for (int i = 0; i < N; i++) {
                doubling[k+1][i] = doubling[k][doubling[k][i]];
            }
        }
    }

    int query(int now, ll K) {
        // クエリ O(log K)
        for (int k = 0; K > 0; k++) {
            if (K & 1) now = doubling[k][now];
            K = K >> 1;
        }
        return now;
    }
};