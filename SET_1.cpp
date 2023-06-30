#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SET {
private:
    vector<int> elements;

public:
    bool isMember(int element) const {
        return find(elements.begin(), elements.end(), element) != elements.end();
    }

    void addElement(int element) {
        elements.push_back(element);
    }

    void powerSet() {
        int n = elements.size();
        int totalSets = 1 << n;

        for (int mask = 0; mask < totalSets; ++mask) {
            vector<int> subset;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    subset.push_back(elements[i]);
                }
            }

            for (int element : subset) {
                cout << element << " ";
            }
            cout << endl;
        }
    }

    bool isSubset(const SET& otherSet) const {
        for (int element : elements) {
            if (!otherSet.isMember(element)) {
                return false;
            }
        }
        return true;
    }

    SET unionSet(const SET& otherSet) const {
        SET result = *this;

        for (int element : otherSet.elements) {
            if (!result.isMember(element)) {
                result.addElement(element);
            }
        }

        return result;
    }

    SET intersection(const SET& otherSet) const {
        SET result;

        for (int element : elements) {
            if (otherSet.isMember(element)) {
                result.addElement(element);
            }
        }

        return result;
    }

    SET complement(const SET& universalSet) const {
        SET result = universalSet;

        for (int element : elements) {
            if (result.isMember(element)) {
                result.elements.erase(remove(result.elements.begin(), result.elements.end(), element), result.elements.end());
            }
        }

        return result;
    }

    SET difference(const SET& otherSet) const {
        SET result;

        for (int element : elements) {
            if (!otherSet.isMember(element)) {
                result.addElement(element);
            }
        }

        return result;
    }

    SET symmetricDifference(const SET& otherSet) const {
        SET unionSet = this->unionSet(otherSet);
        SET intersectionSet = this->intersection(otherSet);

        return unionSet.difference(intersectionSet);
    }

    SET cartesianProduct(const SET& otherSet) const {
        SET result;

        for (int element1 : elements) {
            for (int element2 : otherSet.elements) {
                result.addElement(element1 * element2);
            }
        }

        return result;
    }

    void displaySet() const {
        for (int element : elements) {
            cout << element << " ";
        }

        cout << endl;
    }
};

int main() {
    SET set;

    int choice;
    int element;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Add Element to Set\n";
        cout << "2. Check if Element is Member\n";
        cout << "3. Power Set\n";
        cout << "4. Check Subset\n";
        cout << "5. Union of Sets\n";
        cout << "6. Intersection of Sets\n";
        cout << "7. Complement of Set\n";
        cout << "8. Set Difference\n";
        cout << "9. Symmetric Difference\n";
        cout << "10. Cartesian Product\n";
        cout << "11. Display Set\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter an element to add: ";
                cin >> element;
                set.addElement(element);
                break;

            case 2:
                cout << "Enter an element to check: ";
                cin >> element;
                if (set.isMember(element)) {
                    cout << "Element is a member of the set.\n";
                } else {
                    cout << "Element is not a member of the set.\n";
                }
                break;

            case 3:
                cout << "Power Set:\n";
                set.powerSet();
                break;

            case 4: {
                SET otherSet;
                int otherElement;

                cout << "Enter the other set:\n";
                do {
                    cout << "Enter an element (0 to stop): ";
                    cin >> otherElement;
                    if (otherElement != 0) {
                        otherSet.addElement(otherElement);
                    }
                } while (otherElement != 0);

                if (set.isSubset(otherSet)) {
                    cout << "Set is a subset of the other set.\n";
                } else {
                    cout << "Set is not a subset of the other set.\n";
                }
                break;
            }

            case 5: {
                SET otherSet;
                int otherElement;

                cout << "Enter the other set:\n";
                do {
                    cout << "Enter an element (0 to stop): ";
                    cin >> otherElement;
                    if (otherElement != 0) {
                        otherSet.addElement(otherElement);
                    }
                } while (otherElement != 0);

                SET unionSet = set.unionSet(otherSet);
                cout << "Union of Sets:\n";
                unionSet.displaySet();
                break;
            }

            case 6: {
                SET otherSet;
                int otherElement;

                cout << "Enter the other set:\n";
                do {
                    cout << "Enter an element (0 to stop): ";
                    cin >> otherElement;
                    if (otherElement != 0) {
                        otherSet.addElement(otherElement);
                    }
                } while (otherElement != 0);

                SET intersectionSet = set.intersection(otherSet);
                cout << "Intersection of Sets:\n";
                intersectionSet.displaySet();
                break;
            }

            case 7: {
                SET universalSet;
                int universalElement;

                cout << "Enter the universal set:\n";
                do {
                    cout << "Enter an element (0 to stop): ";
                    cin >> universalElement;
                    if (universalElement != 0) {
                        universalSet.addElement(universalElement);
                    }
                } while (universalElement != 0);

                SET complementSet = set.complement(universalSet);
                cout << "Complement of Set:\n";
                complementSet.displaySet();
                break;
            }

            case 8: {
                SET otherSet;
                int otherElement;

                cout << "Enter the other set:\n";
                do {
                    cout << "Enter an element (0 to stop): ";
                    cin >> otherElement;
                    if (otherElement != 0) {
                        otherSet.addElement(otherElement);
                    }
                } while (otherElement != 0);

                SET differenceSet = set.difference(otherSet);
                cout << "Set Difference:\n";
                differenceSet.displaySet();
                break;
            }

            case 9: {
                SET otherSet;
                int otherElement;

                cout << "Enter the other set:\n";
                do {
                    cout << "Enter an element (0 to stop): ";
                    cin >> otherElement;
                    if (otherElement != 0) {
                        otherSet.addElement(otherElement);
                    }
                } while (otherElement != 0);

                SET symmetricDifferenceSet = set.symmetricDifference(otherSet);
                cout << "Symmetric Difference:\n";
                symmetricDifferenceSet.displaySet();
                break;
            }

            case 10: {
                SET otherSet;
                int otherElement;

                cout << "Enter the other set:\n";
                do {
                    cout << "Enter an element (0 to stop): ";
                    cin >> otherElement;
                    if (otherElement != 0) {
                        otherSet.addElement(otherElement);
                    }
                } while (otherElement != 0);

                SET cartesianProductSet = set.cartesianProduct(otherSet);
                cout << "Cartesian Product:\n";
                cartesianProductSet.displaySet();
                break;
            }

            case 11:
                cout << "Set Elements:\n";
                set.displaySet();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
