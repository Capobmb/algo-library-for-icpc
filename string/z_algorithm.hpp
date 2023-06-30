/*
    Z 配列 (Z[i] := S と S[i:] の最長共通接頭辞) を作成
    O(|S|)
*/
template <typename T> 
V<int> z_algorithm(const V<T> &S) {
    // https://qiita.com/Pro_ktmr/items/16904c9570aa0953bf05 より
    int N = (int)S.size();
    // Z 配列 (Z[i] := S と S[i:] の最長共通接頭辞)
    V<int> Z(N); 
    Z[0] = S.size();
    // i := Z 配列のインデックス
    // j := Z[i] に入るべき値
    int i = 1, j = 0;
    while (i < N) {
        // Z[i] を計算, 伸ばしていく
        while (i + j < N && S[j] == S[i + j]) j++;
        Z[i] = j;

        if (j == 0) {
            i++;
            continue;
        }

        // 計算した Z[i] の結果を再利用する
        // i より先の文字列 S[i + k : ] について, 
        // Z[i + k] がすぐに計算できるか考える
        // もし j (= Z[i]) が Z[k] + k より小なら、そのまま使える
        int k = 1;
        while (k < j && k + Z[k] < j) {
            Z[i + k] = Z[k];
            k++;
        }

        // 伸ばした分だけ i と j を更新
        i += k, j -= k;
    }

    return Z;
} 

/*
    Z 配列 (Z[i] := S と S[i:] の最長共通接頭辞) を作成
    O(|S|)
*/
V<int> z_algorithm(const string &S) {
    int N = S.size();
    V<char> S_v(N);
    for (int i = 0; i < N; i++) S_v[i] = S[i];
    return z_algorithm(S_v);
}