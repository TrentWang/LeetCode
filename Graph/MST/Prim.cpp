#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

// Prim's algorithm to find the Minimum Spanning Tree (MST).
void prims(int vertices, const vector<vector<pii>>& graph) {
    // Priority queue to pick the edge with the smallest weight.
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Visited array to track vertices already included in the MST.
    vector<bool> visited(vertices, false);

    // Start from vertex 0 (arbitrary choice).
    pq.push({0, 0}); // {weight, vertex}

    int mst_weight = 0; // Total weight of the MST.
    vector<pii> mst_edges; // To store the edges of the MST.

    while (!pq.empty()) {
        int weight = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();

        // If the vertex is already visited, skip it.
        if (visited[vertex]) continue;

        // Mark the vertex as visited.
        visited[vertex] = true;
        mst_weight += weight;

        // Add the edge to the MST (skip for the first vertex as it has no parent edge).
        if (weight != 0) {
            mst_edges.push_back({weight, vertex});
        }

        // Traverse all adjacent vertices.
        for (const auto& neighbor : graph[vertex]) {
            int neighbor_vertex = neighbor.second;
            int neighbor_weight = neighbor.first;

            // If the neighbor is not visited, push it into the priority queue.
            if (!visited[neighbor_vertex]) {
                pq.push({neighbor_weight, neighbor_vertex});
            }
        }
    }

    // Output the MST weight and edges.
    cout << "Total weight of MST: " << mst_weight << "\n";
    cout << "Edges in the MST: \n";
    for (const auto& edge : mst_edges) {
        cout << "Weight: " << edge.first << " - Vertex: " << edge.second << "\n";
    }
}