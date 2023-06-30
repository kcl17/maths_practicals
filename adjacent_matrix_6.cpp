#include <iostream>
#include <vector>

using namespace std;

bool isCompleteGraph(const vector<vector<int>>& adjacencyMatrix) {
    int n = adjacencyMatrix.size();

    // Check if each pair of vertices are connected by an edge
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && adjacencyMatrix[i][j] == 0) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n;
    cout << "Enter the number of vertices in the graph: ";
    cin >> n;

    vector<vector<int>> adjacencyMatrix(n, vector<int>(n));

    cout << "Enter the adjacency matrix (0 for no edge, 1 for an edge):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adjacencyMatrix[i][j];
        }
    }

    bool isComplete = isCompleteGraph(adjacencyMatrix);

    if (isComplete) {
        cout << "The given graph is a complete graph." << endl;
    } else {
        cout << "The given graph is not a complete graph." << endl;
    }

    return 0;
}
