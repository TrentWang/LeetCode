void kruskal(int vertices, vector<Edge>& edges) {
    // Sort edges by ascending weight.
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    // Union-Find roots array with path compression.
    vector<int> roots(vertices, -1);

    // Lambda function for `find` with path compression.
    std::function<int(int)> find = [&](int v) {
        if (roots[v] == -1)  // If v is its own root.
            return v;
        else
            return roots[v] = find(roots[v]);  // Path compression.
    };

    vector<Edge> mst;       // To store edges of the MST.
    int mst_weight = 0;     // Total weight of the MST.

    // Iterate through sorted edges and construct the MST.
    for (const auto& edge : edges) {
        int x = find(edge.src);
        int y = find(edge.dest);

        // If including this edge doesn't cause a cycle, include it in the MST.
        if (x != y) {
            mst.push_back(edge);
            mst_weight += edge.weight;
            roots[x] = y;  // Union the two components.
        }
    }

    // Output the MST weight and edges.
    cout << "Total weight of MST: " << mst_weight << "\n";
    cout << "Edges in the MST: \n";
    for (const auto& edge : mst) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << "\n";
    }
}