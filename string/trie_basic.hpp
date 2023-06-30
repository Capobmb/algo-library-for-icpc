/// @brief Trie 木, insert (単語の挿入), search (単語の検索)
/// @tparam alphabet_size 文字列の種類数 (26など)
/// @tparam base 文字列の先頭 (aなど)
template <int alphabet_size, char base>
struct Trie {
    struct Node {
        V<int> children_ids;  // 1. 子頂点の id たち
        int node_char;             // 2. その頂点の文字 : (int)(その文字 - base)
        bool is_endpoint;          // 3. その頂点で終了するか

        // optional
        int has_common;            // 4. その頂点をどれだけの文字列が共有しているか

        Node(int node_char_)
            : node_char(node_char_), is_endpoint(0), has_common(0) {
            children_ids.assign(alphabet_size, -1);
        }
    };

    V<Node> nodes;
    int root;
    Trie() : root(0) { nodes.push_back(Node(root)); }

    void insert(const string& word) {
        int node_id = 0;  // 頂点から下っていく
        for (auto c : word) {
            int cur_char = (int)(c - base);

            int& next_id = nodes[node_id].children_ids[cur_char];
            if (next_id == -1) {  // 次の頂点が存在しない場合
                next_id = (int)nodes.size();
                nodes.push_back(Node(cur_char));
            }
            nodes[node_id].has_common++;  // optional : 4
            node_id = next_id;            // 次頂点へ
        }
        nodes[node_id].has_common++;  // optional : 4
        nodes[node_id].is_endpoint = true;
    }

    bool search(const string& word) {
        int node_id = 0;  // 頂点から下っていく
        for (auto c : word) {
            int cur_char = (int)(c - base);

            int next_id = nodes[node_id].children_ids[cur_char];
            if (next_id == -1) return false;
            node_id = next_id;  // 次頂点へ
        }
        return nodes[node_id].is_endpoint;
    }

    // 最大の LCP を求める
    int get_max_lcp(const string& word) {
        int ret = 0;
        int node_id = 0;
        for (auto c : word) {
            int cur_char = (int)(c - base);

            int next_id = nodes[node_id].children_ids[cur_char];
            if (nodes[next_id].has_common == 1)
                return ret;  // 自分自身だけがその頂点を占有
            ret++;

            node_id = next_id;  // 次頂点へ
        }
        return ret;
    }
};