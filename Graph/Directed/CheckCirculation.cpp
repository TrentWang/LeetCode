// BFS: 拓樸排序
bool CheckCirculation(const vector<vector<int>>& G) {

    int n = G.size();
    vector<int> indegree(n, 0);
    for(const auto& g : G) {
        for(int next : g)
            indegree[next]++;
    }

    vector<int> bfs;
    for(int i = 0; i < n; ++i) {
        if(indegree[i] == 0)
            bfs.push_back(i);
    }

    for (int i = 0; i < bfs.size(); ++i)
        for (int next : G[bfs[i]])
            if (--indegree[next] == 0) 
                bfs.push_back(next);

    return bfs.size() < n;
}


// DFS
bool CheckCirculation(const vector<vector<int>>& G) {

    int n = G.size();
    vector<int> visited(n, 0);

    function<bool(int)> dfs = [&](int curr) {
        if(1 == visited[curr])
            return true;
        if(2 == visited[curr])
            return false;
        
        visited[curr] = 1; // 0: not yet visited; 1: visiting; 2: visited

        for(int next : G[curr]) {
            if(dfs(next))
                return true;
        }

        visited[curr] = 2;
        return false;
    };

    for(int i = 0; i < n; ++i) {
        if(dfs(i))
            return true;
    }

    return false;
}
