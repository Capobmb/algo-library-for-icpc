template <typename T>
struct SimplePrimeFact {
    bool is_prime(T M) {
        if (M == 1) return false;
        for (T i = 2; i * i <= M; i++) {
            if (M % i == 0) {
                return false;
            }
        }
        return true;
    }

    V<T> get_divisor(T M) {
        V<T> res;
        for (T i = 1; i * i <= M; i++) {
            if (M % i == 0) {
                res.push_back(i);
                if (i != M / i) {
                    res.push_back(M / i);
                }
            }
        }
        return res;
    }

    V<pair<T, int>> get_prime_factrization(T M) {
        V<pair<T, int>> res;
        for (T i = 2; i * i <= M; i++) {
            pll pu = {i, 0};
            while (M % i == 0) {
                M /= i;
                pu.second++;
            }
            if (pu.second > 0) res.push_back(pu);
        }
        if (M != 1) res.push_back({M, 1});
        return res;
    }
};