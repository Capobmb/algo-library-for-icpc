template <typename T>
long long count_equal_or_smaller(T elem, vector<T> &v) {
    return upper_bound(v.begin(), v.end(), elem) - v.begin();
}