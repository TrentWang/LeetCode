#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Define a pair to represent the weight and the vertex.
typedef pair<int, int> pii;

// Dijkstra function
void dijkstra(int source, const vector<vector<pii>>& graph, vector<int>& distances) {
    // Priority queue to hold vertices with their current shortest distances.
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Initialize distances to infinity.
    fill(distances.begin(), distances.end(), INT_MAX);

    // Distance to the source is 0.
    distances[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        // If the current distance is already greater than the recorded distance, skip.
        if (current_distance > distances[current_vertex]) {
            continue;
        }

        // Traverse adjacent vertices.
        for (const auto& neighbor : graph[current_vertex]) {
            int weight = neighbor.first;
            int neighbor_vertex = neighbor.second;

            // Calculate the new distance.
            int new_distance = current_distance + weight;

            // If the new distance is shorter, update and push to the priority queue.
            if (new_distance < distances[neighbor_vertex]) {
                distances[neighbor_vertex] = new_distance;
                pq.push({new_distance, neighbor_vertex});
            }
        }
    }
}