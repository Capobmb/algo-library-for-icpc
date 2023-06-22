template <int MOD>
struct ModInt {
    static const int Mod = MOD;
    unsigned x;
    ModInt() : x(0) {}
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    ModInt& operator+=(ModInt that) {
        if ((x += that.x) >= MOD) x -= MOD;
        return *this;
    }
    ModInt& operator-=(ModInt that) {
        if ((x += MOD - that.x) >= MOD) x -= MOD;
        return *this;
    }
    ModInt& operator*=(ModInt that) {
        x = (unsigned long long)x * that.x % MOD;
        return *this;
    }
    ModInt& operator/=(ModInt that) { return *this *= that.inv(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt& operator++() {
        x++;
        if (x == MOD) x = 0;
        return *this;
    }
    ModInt& operator--() {
        if (x == 0) x = MOD;
        x--;
        return *this;
    }
    ModInt operator++(int) {
        ModInt result = *this;
        ++*this;
        return result;
    }
    ModInt operator--(int) {
        ModInt result = *this;
        --*this;
        return result;
    }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const {
        ModInt t;
        t.x = x == 0 ? 0 : Mod - x;
        return t;
    }

    ModInt inv() const {
        long long a = x, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b;
            std::swap(a, b);
            u -= t * v;
            std::swap(u, v);
        }
        return ModInt(u);
    }

    ModInt pow(long long n) const {
        assert(0 <= n);
        ModInt x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }

};
template <int MOD>
ostream& operator<<(ostream& st, const ModInt<MOD> a) {
    st << a.get();
    return st;
};

using mint = ModInt<998244353>;
// using mint = Modint<1000000007>;

using vm = vector<mint>;
using vvm = vector<vm>;
using vvvm = vector<vvm>;