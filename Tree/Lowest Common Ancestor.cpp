int n, level;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int parent, int curr)
{
    tin[curr] = ++timer;
    
    up[curr][0] = parent;
    for (int i = 1; i <= level; ++i)
        up[curr][i] = up[up[curr][i-1]][i-1];

    for (int next : adj[curr]) {
        if (next != parent)
            dfs(curr, next);
    }

    tout[curr] = ++timer;
}

// 判斷 a 是否為 b 的祖先
bool is_ancestor(int a, int b)
{
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b)
{
    if (is_ancestor(a, b))
        return a;
    if (is_ancestor(b, a))
        return b;
    for (int i = level; i >= 0; --i) {
        if (false == is_ancestor(up[a][i], b))
            a = up[a][i];
    }
    return up[a][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    level = ceil(log2(n));
    up.assign(n, vector<int>(level + 1));
    dfs(root, root);
}
