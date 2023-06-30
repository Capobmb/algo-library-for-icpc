template <typename T>
ll count_larger(T elem, V<T> &v) {
    return v.end() - upper_bound(v.begin(), v.end(), elem);
}