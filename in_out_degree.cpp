#include <iostream>
#include <vector>

using namespace std;

// Function to compute the in-degree and out-degree of each vertex in a directed graph
void computeDegree(const vector<vector<int>>& adjacencyList, vector<int>& inDegree, vector<int>& outDegree) {
    int n = adjacencyList.size();

    // Initialize in-degree and out-degree vectors with zeros
    inDegree.assign(n, 0);
    outDegree.assign(n, 0);

    // Compute the in-degree and out-degree for each vertex
    for (int i = 0; i < n; ++i) {
        for (int j : adjacencyList[i]) {
            outDegree[i]++;
            inDegree[j]++;
        }
    }
}

int main() {
    // Example usage

    // Create an adjacency list representation of a directed graph
    vector<vector<int>> adjacencyList = {{1, 2}, {3}, {1, 3}, {0}};

    int n = adjacencyList.size();

    // Create vectors to store in-degree and out-degree of each vertex
    vector<int> inDegree(n);
    vector<int> outDegree(n);

    // Compute the in-degree and out-degree
    computeDegree(adjacencyList, inDegree, outDegree);

    // Output the in-degree and out-degree of each vertex
    for (int i = 0; i < n; ++i) {
        cout << "Vertex " << i << ": In-degree = " << inDegree[i] << ", Out-degree = " << outDegree[i] << endl;
    }

    return 0;
}
