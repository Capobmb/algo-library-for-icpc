template <typename T>
long long count_larger(T elem, vector<T> &v) {
    return v.end() - upper_bound(v.begin(), v.end(), elem);
}