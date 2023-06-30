/* encode: ランレングス圧縮を行う
*/
V<pair<char, int>> encode(const string& str) {
    int n = (int)str.size();
    V<pair<char, int>> ret;
    for (int l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}

/* decode: ランレングス圧縮の復元を行う
*/
string decode(const V<pair<char, int>>& code) {
    string ret = "";
    for (auto p : code) {
        for (int i = 0; i < p.second; i++) {
            ret.push_back(p.first);
        }
    }
    return ret;
}