/*
 * CSC249
 * 4L1-Linear Search
 * Harley Coughlin
 * 03/25/2025
 */

#include <iostream>

using namespace std;


int linear_search(const int arr[], const int& length, const int& key);

int main() {
    const int numbers[]{ 2, 4, 7, 10, 11, 32, 45, 87 };
    const int numbers_size = 8;

    cout << "Numbers: " << numbers[0];
    for (int i = 1; i < numbers_size; ++i) {
        cout << ", " << numbers[i];
    }
    cout << '\n';

    int user_input;
    cout << "Enter a value: ";
    cin >> user_input;

    int result = linear_search(numbers, numbers_size, user_input);
    if (result == -1) {
        cout << "Key not found" << endl;
    } else {
        cout << "Key found at index " << result << endl;
    }

    return 0;
}


int linear_search(const int arr[], const int& length, const int& key) {
    int index = -1;
    for (int i = 0; i < length; ++i) {
        if (arr[i] == key) {
            index = i;
            break;
        }
    }
    return index;
}
