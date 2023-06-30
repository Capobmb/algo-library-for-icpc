template<typename T>
int count_continuous_elements(V<T> &v, bool cyclic=false) {
    int n = (int)v.size();
    if (n == 1) return 1;

    int res = 0, cnt = 0;

    if (cyclic) {
        V<T> v2(2 * n);
        for (int i = 0; i < n; i++) v2[i] = v2[i + n] = v[i];
        for (int i = 0; i < 2 * n - 1; i++) {
            cnt++;
            if (v2[i] != v2[i + 1]) {
                res = max(res, cnt);
                cnt = 0;
            }
        }
        cnt += (v2[2 * n - 2] == v2[2 * n - 1]);
        res = max(res, cnt);
        res = min(res, n);
    } else {
        for (int i = 0; i < n - 1; i++) {
            cnt++;
            if (v[i] != v[i + 1]) {
                res = max(res, cnt);
                cnt = 0;
            }
        }
        cnt += (v[n - 2] == v[n - 1]);
        res = max(res, cnt);
    }

    return res;
}