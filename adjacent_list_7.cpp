#include <iostream>
#include <vector>

using namespace std;

// Function to check if a graph is a complete graph
bool isCompleteGraph(const vector<vector<int>>& adjacencyList) {
    int n = adjacencyList.size();

    // Check each vertex
    for (int i = 0; i < n; ++i) {
        // If any vertex doesn't have edges to all other vertices, it's not a complete graph
        if (adjacencyList[i].size() != n - 1)
            return false;

        // Check if the vertex has edges to all other vertices
        vector<bool> connected(n, false);
        for (int j : adjacencyList[i]) {
            connected[j] = true;
        }

        // If any vertex is not connected to all other vertices, it's not a complete graph
        for (int j = 0; j < n; ++j) {
            if (i != j && !connected[j])
                return false;
        }
    }

    // All vertices have edges to all other vertices, it's a complete graph
    return true;
}

int main() {
    // Example usage

    // Create an adjacency list representation of a graph
    vector<vector<int>> adjacencyList = {{1, 2, 3}, {0, 2, 3}, {0, 1, 3}, {0, 1, 2}};

    // Check if the graph is a complete graph
    bool isComplete = isCompleteGraph(adjacencyList);

    // Output the result
    if (isComplete) {
        cout << "The graph is a complete graph." << endl;
    } else {
        cout << "The graph is not a complete graph." << endl;
    }

    return 0;
}
