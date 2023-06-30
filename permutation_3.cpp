#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to generate permutations recursively
void generatePermutations(const vector<int>& digits, vector<int>& currentPermutation, vector<vector<int>>& result, bool allowRepetition) {
    // If the current permutation has the same size as the input digits,
    // it is a valid permutation and we add it to the result.
    if (currentPermutation.size() == digits.size()) {
        result.push_back(currentPermutation);
        return;
    }

    // Iterate through each digit in the input set
    for (int i = 0; i < digits.size(); ++i) {
        // If repetition is not allowed and the digit already exists in the current permutation,
        // skip it to avoid duplicate permutations.
        if (!allowRepetition && find(currentPermutation.begin(), currentPermutation.end(), digits[i]) != currentPermutation.end()) {
            continue;
        }

        // Add the current digit to the current permutation
        currentPermutation.push_back(digits[i]);

        // Recursively generate permutations with the updated current permutation
        generatePermutations(digits, currentPermutation, result, allowRepetition);

        // Remove the last added digit to backtrack and explore other possibilities
        currentPermutation.pop_back();
    }
}

// Function to get all permutations of a given set of digits
vector<vector<int>> getPermutations(const vector<int>& digits, bool allowRepetition) {
    vector<vector<int>> result; // Store the resulting permutations
    vector<int> currentPermutation; // Store the current permutation being generated

    // Call the recursive function to generate permutations
    generatePermutations(digits, currentPermutation, result, allowRepetition);

    return result;
}

int main() {
    vector<int> digits = {1, 2, 3};

    // Get all permutations without repetition (change to 'true' to allow repetition)
    vector<vector<int>> permutations = getPermutations(digits, false);

    // Display the generated permutations
    for (const auto& permutation : permutations) {
        for (int digit : permutation) {
            cout << digit << " ";
        }
        cout << endl;
    }

    return 0;
}
