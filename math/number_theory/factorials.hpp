template <typename T, int FAC_MAX>
struct Factorials {
    V<T> fac, ifac;
    Factorials() {
        fac.resize(FAC_MAX, 1);
        ifac.resize(FAC_MAX, 1);
        for (int i = 1; i < FAC_MAX; i++) {
            fac[i] = fac[i - 1] * i;
        }
        ifac[FAC_MAX - 1] = T(1) / fac[FAC_MAX - 1];
        for (int i = FAC_MAX - 2; i >= 1; i--) {
            ifac[i] = ifac[i + 1] * T(i + 1);
        }
    }
    T nPr(int n, int r) {
        if (r < 0 || n < r) return T(0);
        return fac[n] * ifac[n - r];
    }
    T nCr(int n, int r) {
        if (r < 0 || n < r) return T(0);
        return fac[n] * ifac[n - r] * ifac[r];
    }
    T nHr(int n, int r) {
        if (n == 0 && r == 0) return T(1);
        if (n <= 0 || r < 0) return 0;
        return nCr(n + r - 1, r);
    }  // nHk = (n+k-1)Ck : n is separator
    T pairCombination(int n) {
        if (n % 2 == 1) return T(0);
        return fac[n] * ifac[n / 2] / (T(2) ^ (n / 2));
    }
    // combination of paris for n
};

// Factorials<mint, 40> comなどとして使用;