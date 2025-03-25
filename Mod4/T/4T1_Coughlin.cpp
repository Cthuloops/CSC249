/**
 * CSC-249
 * 4T1-Local Maximum
 * Harley Coughlin
 * 03/25/2025
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers{ 1, 4, 7, 5, 3, 4};
    int local_max = numbers[0];
    for (int& num : numbers) {
        if (num > local_max) {
            local_max = num;
        }
    }
    cout << "Numbers vector = [" << numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        cout << ", " << numbers[i];
    }
    cout << "]" << '\n';
    cout << "Local max = " << local_max << endl;
    return 0;
}
