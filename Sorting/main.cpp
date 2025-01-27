/**
 * This is a menu driven program to demonstrate sorting algorithms
 * Harley Coughlin
 * CSC 249
 * 01/24/2025
 */


#include <array>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "./Sorter.hpp"
#include "./SelectionSort.hpp"


using namespace std;

void print_menu(const int&);
int get_menu_choice(const int&, istream& = cin);

template<typename Sorter, typename Container>
void selection_sort(const Sorter&, const Container&);

int main() {
    constexpr array<const char*, 1> algos {
        "Selection Sort"
    };

    Sorter<int> int_sorter;
    const vector<int> numbers = {64, 34, 25, 12, 22};

    int input = 0;
    while (input != algos.size() + 1) {
        print_menu(algos.size());
        input = get_menu_choice(algos.size());
        switch (input) {
            case 1:
                int_sorter.set_strategy(new Selection<int>());
                selection_sort(int_sorter, numbers);
                break;
            case algos.size() + 1:
                cout << "Exiting" << endl;
                break;
            default:
                cout << "How'd you get here???\n";
                break;
        }
    }
    return 0;
}


void print_menu(const int& num_choices) {
    cout << "Algorithm Selector\n";
    cout << "1. Selection Sort\n";
    cout << num_choices + 1 << ". Quit\n";
    cout << "Enter your choice: ";
}

int get_menu_choice(const int& num_choices, istream& in) {
    string input;
    int value;
    while (getline(in, input)) {
        istringstream iss(input);
        if (iss >> value) {
            if (value >= 1 && value <= num_choices + 1) {
                return value;
            }
        }
        cout << "Please enter an integer between 1 and " << num_choices + 1
             << ": ";
    }
    return -1;
}

template<typename Sorter, typename Container>
void selection_sort(const Sorter& selection_sorter, const Container& to_sort) {
    cout << "Original: ";
    for (const auto& element : to_sort) {
        cout << element << " ";
    }
    cout << '\n';

    auto ascending = selection_sorter.sort_ascending(to_sort);
    cout << "Ascending: ";
    for (const auto& element : ascending) {
        cout << element << " ";
    }
    cout << '\n';

    auto descending = selection_sorter.sort_descending(to_sort);
    cout << "Descending: ";
    for (const auto& element : descending) {
        cout << element << " ";
    }
    cout << '\n';
}
