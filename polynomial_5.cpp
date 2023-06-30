#include <iostream>
#include <vector>

using namespace std;

int evaluatePolynomial(const vector<int>& coefficients, int n) {
    int result = 0;
    int power = 1;

    for (int i = 0; i < coefficients.size(); ++i) {
        result += coefficients[i] * power;
        power *= n;
    }

    return result;
}

int main() {
    // Store the coefficients of the polynomial function in an array
    vector<int> coefficients = {4, 2, 9};

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // Evaluate the polynomial function at the given value of n
    int result = evaluatePolynomial(coefficients, n);

    cout << "The value of the polynomial function at n = " << n << " is: " << result << endl;

    return 0;
}
