/*
 * CSC249
 * 4H1 - Binary Search and Guessing games - Silver
 * Harley Coughlin
 * 04/01/2025
 */


#include <iostream>
#include <vector>
#include <utility>
#include <limits>


using namespace std;


void bronze();
void silver();
char get_char();
vector<int> get_int_vector();
int binary_search(const vector<int>& numbers, const int& key);


int main() {
    // bronze();
    silver();
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

void silver() {
    int tries = 0;
    cout << "Think of a number between 0 and 99, I'll try to guess it in 5 "
         << "guesses.\n"
         << "Enter '<' if your number is less\n"
         << "'<' if your numbers is higher\n"
         << "or '=' if my guess is correct.\n";
    char input;
    bool correct = false;
    int low = 0;
    int high = 99;
    int guess;
    while (tries < 5 && !correct) {
        guess = (high + low) / 2;
        cout << "Try #" << tries + 1 << "\n";
        cout << "Is your number " << guess << "?\n";
        cout << "Enter '<', '>', or '=': ";
        input = get_char();
        switch (input) {
            case '<':
                high = guess - 1;
                tries++;
                break;
            case '>':
                low = guess + 1;
                tries++;
                break;
            case '=':
                correct = true;
                break;
        }
    }
    if (correct) {
        cout << "I correctly guessed " << guess << " in " << tries << " tries."
             << endl;
    } else {
        cout << "I couldn't guess the number." << endl;
    }
}


char get_char() {
    char input;
    cin >> input;
    while (cin.fail() || !(input == '<' || input == '>' || input == '=')) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter '<', '>', '=': ";
        cin >> input;
    }
    return input;
}


int binary_search(const vector<int>& numbers, const int& key) {
    // Variables to hold the low and high indices of the area being searched.
    // Starts with entire range.
    int low = 0;
    int high = numbers.size() - 1;
    int mid;

    // Loop until "low" passes "high"
    while (high >= low) {
        // Calculate the middle index
        mid = (high + low) / 2;

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
