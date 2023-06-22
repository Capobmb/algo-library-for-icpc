template <typename T>
long long count_smaller(T elem, vector<T> &v) {
    return lower_bound(v.begin(), v.end(), elem) - v.begin();
}