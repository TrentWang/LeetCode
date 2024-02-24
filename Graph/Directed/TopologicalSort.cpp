vector<int> TopologicalSort(const vector<vector<int>>& G) {
    
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

    return bfs;
}