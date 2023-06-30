#include <iostream>
#include <vector>

using namespace std;

class RELATION {
private:
    vector<vector<int>> matrix;

public:
    RELATION(const vector<vector<int>>& inputMatrix) : matrix(inputMatrix) {}

    bool isReflexive() const {
        for (size_t i = 0; i < matrix.size(); ++i) {
            if (matrix[i][i] != 1) {
                return false;
            }
        }
        return true;
    }

    bool isSymmetric() const {
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = i + 1; j < matrix.size(); ++j) {
                if (matrix[i][j] != matrix[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isAntisymmetric() const {
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix.size(); ++j) {
                if (i != j && matrix[i][j] == 1 && matrix[j][i] == 1) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isTransitive() const {
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix.size(); ++j) {
                if (matrix[i][j] == 1) {
                    for (size_t k = 0; k < matrix.size(); ++k) {
                        if (matrix[j][k] == 1 && matrix[i][k] != 1) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    string getRelationType() const {
        bool isEquivalence = isReflexive() && isSymmetric() && isTransitive();
        bool isPartialOrder = isReflexive() && isAntisymmetric() && isTransitive();

        if (isEquivalence) {
            return "Equivalence Relation";
        } else if (isPartialOrder) {
            return "Partial Order Relation";
        } else {
            return "None";
        }
    }
};

int main() {
    // Example usage
    vector<vector<int>> matrix = {{1, 0, 1},
                                  {0, 1, 0},
                                  {1, 0, 1}};

    RELATION relation(matrix);

    cout << "Reflexive: " << (relation.isReflexive() ? "Yes" : "No") << endl;
    cout << "Symmetric: " << (relation.isSymmetric() ? "Yes" : "No") << endl;
    cout << "Antisymmetric: " << (relation.isAntisymmetric() ? "Yes" : "No") << endl;
    cout << "Transitive: " << (relation.isTransitive() ? "Yes" : "No") << endl;
    cout << "Relation Type: " << relation.getRelationType() << endl;

    return 0;
}
