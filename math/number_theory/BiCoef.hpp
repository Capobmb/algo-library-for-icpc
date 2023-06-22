#include <bits/stdc++.h>


template<long long MOD = 998244353>
struct Bicoef {
    std::vector<long long> fac, finv, inv;
    Bicoef(int Max) : fac(Max), finv(Max), inv(Max) {
        assert(Max < MOD);
         fac[0] =  fac[1] = 1;
        finv[0] = finv[1] = 1;
                   inv[1] = 1;
        for (long long i = 2; i < Max; i++) {
            fac[i]  = fac[i-1] * i % MOD;
            inv[i]  = MOD - inv[MOD%i] * (MOD/i) % MOD;
            if(inv[i] == MOD) inv[i] = 0;
            finv[i] = finv[i-1] * inv[i] % MOD;
        }
    }
    inline long long com(int n, int k) const {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * finv[k] % MOD * finv[n-k] % MOD;
    }
    inline long long perm(int n, int k) const {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * finv[n-k] % MOD;
    }
    inline long long fact(int n) const { return fac[n]; }
};
// Bicoef<998244353> bf(n);