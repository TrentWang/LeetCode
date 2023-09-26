int timer = 0;
vector<int> in, out;

void dfs(int parent, int curr)
{
    in[curr] = ++timer;
    for (int child : adj[curr]) {
        if (child != parent)
            dfs(curr, child);
    }
    out[curr] = ++timer;
}


// 判斷 node A 是否是 node B 的祖先
bool is_ancestor(int a, int b)
{
    return in[a] <= in[b] && out[b] <= out[a];
}
