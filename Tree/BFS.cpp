// Buttom up BFS
// n: how many nodes in a tree
// edges: undirected edges, edges[i].size() == 2, edges[i][0] and edges[i][1] are connected
// values: value of each node, values.size() == n
void BFS(int n, vector<vector<int>>& edges, vector<int>& values) {
    vector<vector<int>> G(n);
    for(const auto &e : edges) {
        G[e[0]].push_back(e[1]);
        G[e[1]].push_back(e[0]);        
    }
    
    queue<int> q;
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        cnt[i] = G[i].size();
        if (cnt[i] < 2)
            q.push(i);
    }
    
    vector<int> sum = values;
    while(q.size()) {
        int i = q.front();
        q.pop();
        --cnt[i];
        for (int j : G[i]) {
            if (cnt[j] == 0)
                continue;

            sum[j] += sum[i];

            if (--cnt[j] == 1)
                q.push(j);
        }
    }
}