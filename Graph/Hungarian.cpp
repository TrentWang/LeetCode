int num_nodes = 100000;
vector<int> next[num_nodes];
int match[num_nodes] = {-1};

bool dfs(int i, vector<bool>& visited) {
    for (int j : next[i]) {
        if (visited[j]) 
            continue;
        
        visited[j] = true;
        
        if (match[j] == -1 || dfs(match[j], visited)) {
            match[i] = j;
            match[j] = i;
            return true;
        }
    }
    return false;
}

int minimumOperations(vector<vector<int>>& grid) {
    // build next[] ...

    vector<bool>visited(num_nodes);
    
    int count = 0;
    for (int i = 0; i < num_nodes; i++) {
        if (match[i] != -1) 
            continue;
        visited.assign(num_nodes, 0);
        if (dfs(i, visited))
            count++;            
    }
    
    return count;
}
                                        
