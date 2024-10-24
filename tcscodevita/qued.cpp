#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> expertise;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> component;

void dfs(int node) {
    visited[node] = true;
    component.push_back(node);
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, c;
    cin >> n >> c;

    expertise.resize(n);
    adj.resize(n);
    visited.resize(n, false);

    // Read the conflicting pairs
    for (int i = 0; i < c; ++i) {
        int u, v;
        cin >> u >> v;
        --u; // convert to 0-based index
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Read the expertise values
    for (int i = 0; i < n; ++i) {
        cin >> expertise[i];
    }

    int max_expertise = 0;

    // Explore each connected component
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            component.clear();
            dfs(i);

            // Now we have a connected component in `component`
            int sum_expertise = 0;
            for (int member : component) {
                sum_expertise += expertise[member];
            }
            max_expertise = max(max_expertise, sum_expertise);
        }
    }

    cout << max_expertise;

    return 0;
}
