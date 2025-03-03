/**
 * CSC-249
 * M2.H1 - Recursion
 * Harley Coughlin
 * 02/24/2025
 */


#include <iostream>
#include <limits>
#include <vector>

using namespace std;


int iterative_binary(const vector<int>& list, const int& key);
int recursive_binary(const vector<int>& list, const int& low, const int& high, const int& key);
void iterative_fibonacci(const int& number);
int recursive_fibonacci(const int& number);


int main() {
    vector<int> numbers { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


    cout << "Numbers: ";
    cout << numbers[0];
    for (int i = 1; i < numbers.size(); ++i) {
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
            cout << "Please enter a valid int.\n";
        }
    }

    cout << "Using iterative binary search:\n";
    int x = iterative_binary(numbers, user_input);
    if (x != -1) {
        cout << "Found " << user_input << " at index " << x << "." << endl;
    } else {
        cout << user_input << " was not found." << endl;
    }

    cout << "Using recursive binary search:\n";
    x = recursive_binary(numbers, 0, numbers.size(), user_input);
    if (x != -1) {
        cout << "Found " << user_input << " at index " << x << "." << endl;
    } else {
        cout << user_input << " was not found." << endl;
    }

    cout << "Iterative fibonacci: ";
    iterative_fibonacci(10);
    cout << '\n';

    cout << "Recursive fibonacci: ";
    int total = recursive_fibonacci(10);
    cout << total << '\n';

    return 0;
}


int iterative_binary(const vector<int>& list, const int& key) {
    int index = -1;
    int low = 0;
    int high = list.size();
    while (high >= low) {
        int mid = (high + low) / 2;
        if (list[mid] < key) {
            low = mid + 1;
        } else if (list[mid] > key) {
            high = mid - 1;
        } else {
            index = mid;
            break;
        }
    }
    return index;
}

int recursive_binary(const vector<int>& list, const int& low, const int& high, const int& key) {
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (list[mid] < key) {
        return recursive_binary(list, mid + 1, high, key);
    } else if (list[mid] > key) {
        return recursive_binary(list, low, mid - 1, key);
    }
    return mid;
}


void iterative_fibonacci(const int& number) {
    if (number < 1) {
        return;
    }
    int x = 0;
    int y = 1;
    cout << x; 
    for (int i = 0; i < number; ++i) {
        cout << ", " << y;
        int next = x + y;
        x = y;
        y = next;
    }

}

int recursive_fibonacci(const int& number) {
    if (number == 0) {
        return 0;
    } else if (number == 1) {
        return 1;
    }
    else {
        return recursive_fibonacci(number - 1) + recursive_fibonacci(number - 2);
    }
}
