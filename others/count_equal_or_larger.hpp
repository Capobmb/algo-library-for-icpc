template <typename T>
ll count_equal_or_larger(T elem, V<T> &v) {
    return v.end() - lower_bound(v.begin(), v.end(), elem);
}