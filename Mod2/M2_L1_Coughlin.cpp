/**
 * Harley Coughlin
 * CSC 249
 * 2L1 - Linear search
 * 02/16/2025
 */

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int linear_search(const vector<double>& list, const double& search_for);


int main() {
    vector<double> numbers { 1.0, 20.0, 24.38, 10.0, 0.10, 999.0, 0.999 };

    cout << "Numbers: ";
    cout << numbers[0];
    for (int i = 1; i < numbers.size(); ++i) {
        cout << ", " << numbers[i];
    }
    cout << '\n';


    double user_input;
    bool valid_input = false;
    while (!valid_input) {
        cout << "Enter a value: ";
        if (cin >> user_input) {
            valid_input = true;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid double.\n";
        }
    }
    int x = linear_search(numbers, user_input);
    if (x != -1) {
        cout << "Found " << user_input << " at index " << x << "." << endl;
    } else {
        cout << user_input << " was not found." << endl;
    }

    return 0;
}


int linear_search(const vector<double>& list, const double& search_for) {
    int index = -1;
    for (int i = 0; i < list.size(); ++i) {
        if (list[i] == search_for) {
            index = i;
            break;
        }
    }
    return index;
}
