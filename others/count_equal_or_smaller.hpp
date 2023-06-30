template <typename T>
ll count_equal_or_smaller(T elem, V<T> &v) {
    return upper_bound(v.begin(), v.end(), elem) - v.begin();
}