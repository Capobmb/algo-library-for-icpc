/// @return a^n mod MOD
constexpr ll modpow(ll a, ll n, ll MOD) {
    ll res = 1;
    a %= MOD;
    while(n > 0) {
        if(n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

/// @return a^n
constexpr ll powll(ll a, ll n) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}