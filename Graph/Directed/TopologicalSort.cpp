vector<int> TopologicalSort(const vector<vector<int>>& G) {
    
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

    vector<int> ans;
    while(!q.empty()) {
        int curr = q.front();	
        q.pop();
        ans.push_back(curr);

        for(int next : G[curr]) {
            --indegree[next];
            if(indegree[next] == 0)	
                q.push(next);
        }
    }

    return ans;
}