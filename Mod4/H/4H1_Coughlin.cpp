/*
 * CSC-249
 * 4H1 - Binary Search and Guessing games - Bronze
 * Harley Coughlin
 * 04/01/2025
 */


#include <iostream>
#include <vector>
#include <utility>


using namespace std;


vector<int> get_int_vector();
int binary_search(const vector<int>& numbers, const int& key);
void bronze();


int main() {
    bronze();
    return 0;
}


void bronze() {
    vector<int> numbers = get_int_vector();
    cout << "You entered: ";
    for (const auto& num : numbers) {
        cout << num << " ";
    }
    cout << '\n';

    int input;
    cout << "Enter a number to search for: ";
    cin >> input;
    int result = binary_search(numbers, input);
    if (result != -1) {
        cout << "Key " << input << " found at index " << result << endl;
    } else {
        cout << "Key could not be found." << endl;
    }
}


vector<int> get_int_vector() {
    cout << "Enter integers, either a list separated by spaces or numbers "
         << "separated by newline.\n"
         << "Enter any non-int to finish.\n";
    vector<int> numbers;
    int input;
    while (cin >> input) {
        numbers.push_back(input);
    }
    if (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
    }
    return std::move(numbers);
}


int binary_search(const vector<int>& numbers, const int& key) {
    // Variables to hold the low and high indices of the area being searched.
    // Starts with entire range.
    int low = 0;
    int high = numbers.size() - 1;

    // Loop until "low" passes "high"
    while (high >= low) {
        // Calculate the middle index
        int mid = (high + low) / 2;

        // Cut the range to either the left or right half,
        // unless numbers[mid] is the key
        if (numbers[mid] < key) {
            low = mid + 1;
        } else if (numbers[mid] > key) {
            high = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;  // not found
}
