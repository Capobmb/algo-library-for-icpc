template <typename T>
long long count_equal_or_larger(T elem, vector<T> &v) {
    return v.end() - lower_bound(v.begin(), v.end(), elem);
}