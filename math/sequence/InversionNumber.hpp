#include<bits/stdc++.h>
#include"data_structure/BIT.hpp"

/* inversion_number
    返り値：v の転倒数
    注意：v は座標圧縮済みである必要がある i.e. 0 <= v[i] < v.size() である必要がある
    計算量 : O(LlogL) ; L=v.size()
*/
template<typename T>
ll inversion_number(const V<T>& v) {
    int n = v.size();
    ll ret = 0;
    BIT<ll> fw(n);
    for(int i = 0; i < n; i++) {
        ret += fw.sum(v[i] + 1, n);
        fw.add(v[i], 1LL);
    }
    return ret;
}