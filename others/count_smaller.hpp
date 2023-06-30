template <typename T>
ll count_smaller(T elem, V<T> &v) {
    return lower_bound(v.begin(), v.end(), elem) - v.begin();
}