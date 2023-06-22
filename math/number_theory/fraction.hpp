struct Fraction {
    long long numerator;        // 分子
    long long denominator;      // 分母
    bool is_inf = false;        // +- infinity か
    bool is_zero = false;       // 0 か
    bool is_minus = false;      // 数として負か
    bool is_both_zero = false;  // 分母も分子も 0 (扱い分からん！)

    Fraction(long long numerator_, long long denominator_) {
        if (numerator_ == 0) is_zero = true;
        if (denominator_ == 0) {
            if (numerator_ == 0) is_both_zero = true;
            is_inf = true;
            if (numerator_ < 0) is_minus = true;
        } else {
            is_inf = false;
            if ((numerator_ < 0 && denominator_ > 0) ||
                (numerator_ > 0 && denominator_ < 0)) {
                is_minus = true;
                numerator_ = abs(numerator_);
                denominator_ = abs(denominator_);
            }
            if (numerator_ != 0) {
                long long g = __gcd(denominator_, numerator_);
                denominator = denominator_ / g;
                numerator = numerator_ / g;
            } else {
                denominator = denominator_;
                numerator = numerator_;
            }
        }
    }

    bool operator==(const Fraction& other) const {
        // 両方 +- inf のとき
        if (is_minus == other.is_minus && is_inf && other.is_inf) return true;
        if (is_both_zero != other.is_both_zero) return false;
        // 両方 0 のとき
        if (numerator == 0 && other.numerator == 0) return true;
        // それ以外
        return is_minus == other.is_minus && denominator == other.denominator &&
               numerator == other.numerator;
    }

    // オーバーフロー注意
    bool operator<(const Fraction& other) const {
        if (is_inf && other.is_inf) return is_minus < other.is_minus;
        if (is_inf) return true;
        if (is_minus && is_inf) return false;

        if (numerator == 0) {
            return other.numerator && !other.is_minus;
        }

        if (is_minus) {
            if (!other.is_minus) return true;
            return numerator * other.denominator >
                   other.numerator * denominator;
        } else {
            return numerator * other.denominator <
                   other.numerator * denominator;
        }
    }

    // -1 倍する
    Fraction minus() {
        if (is_minus) return Fraction{numerator, denominator};
        return Fraction{-numerator, denominator};
    }

    // 逆数を取る
    Fraction inv() {
        if (is_minus) return Fraction{-denominator, numerator};
        return Fraction{denominator, numerator};
    }
};

ostream& operator<<(ostream& st, const Fraction f) {
    if (f.is_minus) st << "-";
    st << f.numerator << "/" << f.denominator;
    return st;
};