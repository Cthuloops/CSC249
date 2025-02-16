/**
 * Harley Coughlin
 * CSC 249
 * 2L2 - Binary search
 * 02/16/2025
 */

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int binary_search(const int* numbers, const int& numbers_size, const int& search_for);


int main() {
    constexpr int numbers[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    constexpr int numbers_size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Numbers: ";
    cout << numbers[0];
    for (int i = 1; i < numbers_size; ++i) {
        cout << ", " << numbers[i];
    }
    cout << '\n';


    int user_input;
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
    int x = binary_search(numbers, numbers_size, user_input);
    if (x != -1) {
        cout << "Found " << user_input << " at index " << x << "." << endl;
    } else {
        cout << user_input << " was not found." << endl;
    }

    return 0;
}


int binary_search(const int* numbers, const int& numbers_size, const int& search_for) {
    int index = -1;
    int low = 0;
    int high = numbers_size - 1;
    string y;
    while (high >= low) {
        int mid = (high + low) / 2;
        if (numbers[mid] < search_for) {
            low = mid + 1;
        } else if (numbers[mid] > search_for) {
            high = mid - 1;
        } else {
            index = mid;
            break;
        }
    }
    return index;
}
