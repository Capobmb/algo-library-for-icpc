#ifndef INCLUDED_MAIN
#define INCLUDED_MAIN
#include __FILE__

// #include <atcoder/all>
// const ll MOD = 998244353;
// const ll MOD = 1000000007; // 1e9 + 7
// using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;

void solve() {

}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(3);

    int testcases = 1;
    // cin >> testcases;
    while(testcases--) solve();
}

#else  // INCLUDED_MAIN

#ifdef poyo

#include "my_pch.h"

#else

#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <class T> using V = vector<T>;
template <class T, class U> using P = pair<T, U>;
template <class T> using max_heap = priority_queue<T>;
template <class T> using min_heap = priority_queue<T, vector<T>, greater<T> >;
using vi = V<int>;
using vvi = V<vi>;
using vvvi = V<vvi>;
using vl = V<ll>;
using vvl = V<vl>;
using vvvl = V<vvl>;
using vb = V<bool>;
using vvb = V<vb>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vpl = V<pll>;

#define _overload(_1, _2, _3, name, ...) name
#define rep1(n) rep3(____, 0, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) for (ll i = (a); i < (ll)(b); i++)
#define rep(...) _overload(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

#define rrep(i, a, b) for (ll i = a; i >= b; i--)
#define fore(i, a) for (auto&& i : a)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define pb push_back

#define UNIQUIFY(v) v.erase(unique(v.begin(), v.end()), v.end());
#define out(x) \
    { cout << fixed << setprecision(12) << x << "\n"; }
#define dbg(x) \
    { cerr << #x << ": " << x << "\n"; }
#define inc(x, l, r) ((l) <= (x) and (x) < (r))

// debug macro.
#ifdef LOCAL
void debug_out() { cerr << endl; }
template <class Head, class... Tail>
void debug_out(Head H, Tail... T) {
    cerr << ", " << H;
    debug_out(T...);
}
#define debug(...) cerr << "Line " << __LINE__ << " : " << #__VA_ARGS__ << " ,,", debug_out(__VA_ARGS__)
#else
#define debug(...) (void(0))
#endif

constexpr int INFI = 1 << 30;
constexpr ll INFL = 1LL << 60;
constexpr char ENDL = '\n';
constexpr int dy[] = {0, 1, 0, -1};
constexpr int dx[] = {1, 0, -1, 0};

template <typename S, typename T>
bool chmax(S& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename S, typename T>
bool chmin(S& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

template <class... T>
constexpr auto min(T... a) {
    return min(initializer_list<common_type_t<T...>>{a...});
}
template <class... T>
constexpr auto max(T... a) {
    return max(initializer_list<common_type_t<T...>>{a...});
}
ll max(ll lhs, ll rhs) { return std::max<ll>(lhs, rhs); }
ll min(ll lhs, ll rhs) { return std::min<ll>(lhs, rhs); }

int equal_or_smaller_nums(int elem, V<int> &v) {
    return upper_bound(v.begin(), v.end(), elem) - v.begin();
}
int equal_or_smaller_nums(ll elem, V<ll> &v) {
    return upper_bound(v.begin(), v.end(), elem) - v.begin();
}

int smaller_nums(int elem, V<int> &v) {
    return lower_bound(v.begin(), v.end(), elem) - v.begin();
}
int smaller_nums(ll elem, V<ll> &v) {
    return lower_bound(v.begin(), v.end(), elem) - v.begin();
}

int equal_or_larger_nums(int elem, V<int> &v) {
    return v.end() - lower_bound(v.begin(), v.end(), elem);
}
int equal_or_larger_nums(ll elem, V<ll> &v) {
    return v.end() - lower_bound(v.begin(), v.end(), elem);
}

int larger_nums(int elem, V<int> &v) {
    return v.end() - upper_bound(v.begin(), v.end(), elem);
}
int larger_nums(ll elem, V<ll> &v) {
    return v.end() - upper_bound(v.begin(), v.end(), elem);
}

template <class T, class U>
istream& operator>>(istream& is, P<T, U>& p) {
    return is >> p.first >> p.second;
}

template <typename T>
ostream& operator<<(ostream& os, const V<T>& v) {
    int sz = (int)v.size();
    for (int i = 0; i < sz; i++) {
        os << v[i] << (i == sz - 1 ? "" : " ");
    }
    return os;
}

template <class T, class U>
ostream& operator<<(ostream& os, P<T, U>& p) {
    return os << p.first << ' ' << p.second;
}

template <typename T>
istream& operator>>(istream& is, V<T>& v) {
    int sz = (int)v.size();
    for (int i = 0; i < sz; i++) {
        is >> v[i];
    }
    return is;
}

int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
int dy[] = {-1, 0, 1, 0, 1, -1, -1, 1};

#endif  // poyo
#endif  // INCLUDED_MAIN