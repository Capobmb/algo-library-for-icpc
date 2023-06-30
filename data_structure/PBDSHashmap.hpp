#include <bits/stdc++.h>
//----------------------

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T, class U>
using hash_table = __gnu_pbds::gp_hash_table<T, U>;

struct llhash {
    ll seed;
    llhash()
        : seed(std::chrono::high_resolution_clock::now()
                   .time_since_epoch()
                   .count()) {}
    ll operator()(ll x) const { return x ^ seed; }
};
using robust_hash_table = __gnu_pbds::gp_hash_table<ll, ll, llhash>;

template <class T, class U>
bool count(hash_table<T, U>& mp, T&& key) {
    return mp.find(key) != mp.end();
}