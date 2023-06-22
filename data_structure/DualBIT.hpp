#include<bits/stdc++.h>
#include"BIT.hpp"

template <typename T>
struct dual_bit {
    dual_bit(int n) : fw(n+1) {}
    void add(int l, int r, T x) {
        fw.add(l, x);
        fw.add(r, -x);
    }
    T get(int p) {
        return fw.sum(0, p+1);
    }
private:
    BIT<T> fw;
};