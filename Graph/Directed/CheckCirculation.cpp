// BFS: 拓樸排序
bool CheckCirculation(const vector<vector<int>>& G) {

    int n = G.size();
    vector<int> indegree(n, 0);
    for(const auto& g : G) {
        for(int next : g)
            indegree[next]++;
    }

    queue<int> q;
    for(int i = 0; i < n; ++i) {
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()) {
        int curr = q.front();	
        q.pop();
        for(int next : G[curr]) {
            --indegree[next];
            if(indegree[next] == 0)	
                q.push(next);
        }
    }

    for(int i = 0; i < n; ++i) {
        if(indegree[i] != 0)
            return true;
    }

    return false;
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
