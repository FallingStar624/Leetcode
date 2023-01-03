#include <vector>
#include <algorithm>
using namespace std;
vector<int>::iterator iter;

class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<int>> ans;
    bool visited[1000];
    void dfs(int v, bool* visited) {
        if (visited[v]) {
            return;
        } else {
            visited[v] = true;
        }
        for (int i=0; i<adj[v].size(); i++) {
            int anc_node = adj[v][i];
            if (not visited[anc_node]) {
                dfs(anc_node, visited);
            };
            vector<int> tmp(1000);
            sort(ans[v].begin(), ans[v].end());
            sort(ans[anc_node].begin(), ans[anc_node].end());
            iter = set_union(ans[v].begin(), ans[v].end(), ans[anc_node].begin(), ans[anc_node].end(), tmp.begin());
            tmp.resize(iter-tmp.begin());
            ans[v] = tmp;
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // make adj (to->from)
        for (int i=0; i<n; i++) {
            vector<int> tmp;
            adj.push_back(tmp);
            ans.push_back(tmp);
        }
        for (int i=0; i<edges.size(); i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            adj[to].push_back(from);
            ans[to].push_back(from);
        }
        // dfs
        for (int node=0; node<n; node++) {
            dfs(node, visited);
        }
        return ans;
    }
};
