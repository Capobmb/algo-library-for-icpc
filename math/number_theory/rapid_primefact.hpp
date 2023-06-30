/*  PrimeFact
    init(N): 初期化。O(N log log N)
    get(n): クエリ。素因数分解を求める。O(log n)
 */
struct RapidPrimeFact {
    int MAX;
    V<int> spf;
    RapidPrimeFact(int N) : MAX(N) { init(N); }
    void init(int N) { // 前処理。spf を求める
        spf.assign(N + 1, 0);
        for (int i = 0; i <= N; i++) spf[i] = i;
        for (int i = 2; i * i <= N; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= N; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    bool is_prime(int n) const {
        if (n == 1) return false;
        return spf[n] == n;
    }

    V<int> primes() const {
        V<int> p;
        for(int i = 2; i < MAX; i++) {
            if(is_prime(i)) p.push_back(i);
        }
        return p;
    }

    V<pair<int, int>> get_prime_factorization(int n) { 
        V<pair<int, int>> res;
        pair<int, int> cur = {spf[n], 0};
        while (n != 1) {
            if (spf[n] == cur.first) {
                cur.second++;
            } else {
                res.push_back(cur);
                cur = {spf[n], 1};
            }
            n /= spf[n];
        }
        res.push_back(cur);
        return res;
    }
};