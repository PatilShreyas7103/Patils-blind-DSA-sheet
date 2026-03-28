// Shortest path in Directed Acyclic Graph (DAG)
// Link: https://www.geeksforgeeks.org/shortest-path-directed-acyclic-graph/

#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <numeric>

class Solution {
private:
    void topoSort(int node, vector<pair<int,int>> adj[], vector<int> &vis, stack<int> &st) {
        vis[node] = 1;
        for (auto &it : adj[node]) {
            int v = it.first;
            if (!vis[v]) topoSort(v, adj, vis, st);
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
        vector<pair<int,int>> adj[N];
        for (int i = 0; i < M; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        vector<int> vis(N, 0);
        stack<int> st;
        for (int i = 0; i < N; ++i) {
            if (!vis[i]) topoSort(i, adj, vis, st);
        }

        const int INF = 1e9;
        vector<int> dist(N, INF);
        dist[0] = 0;

        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (dist[node] != INF) {
                for (auto &it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        for (int i = 0; i < N; ++i) {
            if (dist[i] == INF) dist[i] = -1;
        }

        return dist;
    }
};
