int longest_common_sequence(string &S, string &T) {
    int s_sz = S.size();
    int t_sz = T.size();
    vector<vector<int>> dp(s_sz + 1, vector<int>(t_sz + 1));
    rep(i, s_sz) {
        rep(j, t_sz) {
            chmax(dp[i+1][j+1], dp[i+1][j]);
            chmax(dp[i+1][j+1], dp[i][j+1]);
            if (S[i] == T[j]) chmax(dp[i+1][j+1], dp[i][j] + 1);
        }
    }
    return dp[s_sz][t_sz];
}