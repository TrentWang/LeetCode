// https://github.com/wisdompeak/LeetCode/tree/master/DFS/332.Reconstruct-Itinerary
void DFS(unordered_map<string, queue<string>>& Map, string start, vector<string>& path) // 假設 Map 確認含有尤拉路徑
{
    while (Map[start].size() > 0)
    {
        string nextStart = Map[start].front();
        Map[start].pop();
        DFS(Map, nextStart, path);
    }
    path.push_back(start);
}