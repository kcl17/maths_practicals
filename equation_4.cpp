#include <iostream>
#include <vector>

using namespace std;

void printSolution(const vector<int>& solution) {
    for (size_t i = 0; i < solution.size(); ++i) {
        if (i != 0)
            cout << " + ";
        cout << solution[i];
    }
    cout << endl;
}

void solveEquation(int n, int C, vector<int>& solution, int currentSum) {
    if (currentSum > C) {
        return;
    }

    if (solution.size() == n) {
        if (currentSum == C) {
            printSolution(solution);
        }
        return;
    }

    for (int i = 0; i <= C - currentSum; ++i) {
        solution.push_back(i);
        solveEquation(n, C, solution, currentSum + i);
        solution.pop_back();
    }
}

int main() {
    int n, C;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of C: ";
    cin >> C;

    vector<int> solution;
    cout << "Solutions of the equation: " << endl;
    solveEquation(n, C, solution, 0);

    return 0;
}
