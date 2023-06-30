template <typename T>
ll count_equal(T elem, V<T> &v) {
    return upper_bound(v.begin(), v.end(), elem) -
           lower_bound(v.begin(), v.end(), elem);
}