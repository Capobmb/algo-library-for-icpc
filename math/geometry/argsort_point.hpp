struct Point {
    long long x, y;

    Point(long long x_ = 0, long long y_ = 0) : x(x_), y(y_) {}

    // bool operator== (const Point& other) const {
    //     return x == other.x && y == other.y;
    // }
    // bool operator!= (const Point& other) const {
    //     return x != other.x || y != other.y;
    // }

    // // 通常の比較演算子 (pair と同じ挙動)
    // bool operator< (const Point& other) const {
    //     if (x == other.x) return y < other.y;
    //     else return x < other.x;
    // }

    // 偏角ソート用 (角度が等しければ true)
    bool operator== (const Point& other) const {
        return x * other.y - other.x * y == 0;
    }
    bool operator!= (const Point& other) const {
        return x * other.y - other.x * y != 0;
    }

    // 偏角ソート用 (反時計回りの偏角が 180 度未満なら true)
    bool operator< (const Point& other) const {
        return x * other.y - other.x * y > 0;
    }
};