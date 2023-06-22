template <typename T>
long long count_equal(T elem, vector<T> &v) {
    return upper_bound(v.begin(), v.end(), elem) -
           lower_bound(v.begin(), v.end(), elem);
}