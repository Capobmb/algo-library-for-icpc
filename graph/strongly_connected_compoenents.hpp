#include "decl.hpp"

template <typename T>
struct Edge {
    int to;
    T cost;
};

template <typename T>
struct StronglyConnectedComponents {
    int vertex_size;
    vector<vector<Edge<T>>> edges, r_edges;
    vector<int> order, component;
    vector<bool> used, r_used;

    StronglyConnectedComponents(vector<vector<Edge<T>>> &edges_) : 
    vertex_size(edges_.size()), edges(edges_), 
    r_edges(vertex_size), component(vertex_size), 
    used(vertex_size), r_used(vertex_size) {
            for (int cv = 0; cv < vertex_size; cv++) {
                for (auto& [nv, cost] : edges[cv]) {
                    r_edges[nv].push_back({cv, cost});
                }
            }
            for (int cv = 0; cv < vertex_size; cv++) {
                if (!used[cv]) dfs(cv);
            }
            reverse(order.begin(), order.end());
            int component_idx = 0;
            for (auto& cv : order) {
                if (!r_used[cv]) {
                    r_dfs(cv, component_idx);
                    component_idx++;
                }
            }
    }

    void dfs(int cur_to) {
        used[cur_to] = true;
        for (auto& [nxt_to, nxt_cost] : edges[cur_to]) {
            if (!used[nxt_to]) dfs(nxt_to);
        }
        order.push_back(cur_to);
    }
    void r_dfs(int cur_to, int component_idx) {
        r_used[cur_to] = true;
        component[cur_to] = component_idx;
        for (auto& [nxt_to, nxt_cost] : r_edges[cur_to]) {
            if (!r_used[nxt_to]) r_dfs(nxt_to, component_idx);
        }
    }

    bool is_same(int u, int v) {return component[u] == component[v];}

    vector<vector<int>> rebuild() {
        int rebuild_vertex_size = *max_element(component.begin(), component.end()) + 1;
        dbg(rebuild_vertex_size);
        vector<vector<int>> res(rebuild_vertex_size);
        set<pair<int, int>> connected;
        for (int cv = 0; cv < vertex_size; cv++) {
            for (auto& [nv, ncost] : edges[cv]) {
                if (component[cv] != component[nv] and !connected.count({cv, nv})) {
                    connected.insert({cv, nv});
                    res[component[cv]].push_back(component[nv]);
                }
            }
        }
        return res;
    }
};