#include<bits/stdc++.h>

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

/**
 * @brief Discrete Logarithmic Function utilizing Baby-step Giant-step Algorithm. Time Complexity = O(√p).
 * @param p Prime
 * @return Minimum X such that a^x = b mod p <=> x = log_a(b) mod p. If not found -1.
 */
ll discrete_log(ll a, ll b, ll p) {
    ll r = sqrt(p) + 1;

    std::unordered_map<ll, ll> table;
    ll ap = 1;
    for(int i = 0; i < r; i++) {
        if(!table.count(ap)) table[ap] = i;
        ap = ap * a % p;
    }

    const ll gamma = modpow(modpow(a, r, p), p-2, p);
    ll gp = 1;
    for(ll i = 0; i < r; i++) {
        if(table.count(gp * b % p)) {
            return i * r + table[gp * b % p];
        }
        gp = gp * gamma % p;
    }
    return -1;
}