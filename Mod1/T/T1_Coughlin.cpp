/**
 * CSC 249
 * 1.T.1 - Hello, Data Structures
 * Harley Coughlin
 * 01/17/2025
 */


#include <iostream>
using namespace std;

const int LINE_LENGTH = 10;


void add_person(int line[LINE_LENGTH], int person, int* people_amount);
void remove_person(int line[LINE_LENGTH], int* people_amount);

int main() {

    int queue[LINE_LENGTH];
    int num_people = 0;
    int* people_amount = &num_people;

    cout << "Joining the line:\n";
    // Add LINE_LENGTH people to line
    for (int i = 0; i < LINE_LENGTH; i++) {
        add_person(queue, i * 2, people_amount);
    }

    cout << "\n";

    cout << "Leaving the line:\n";
    // Remove people from line
    for (int i =0; i < LINE_LENGTH; i++) {
        remove_person(queue, people_amount);
    }

    return 0;
}

void add_person(int line[LINE_LENGTH], int person, int* people_amount) {
    if (*people_amount < LINE_LENGTH) {
        line[*people_amount] = person;
        *people_amount += 1;
        cout << "Person " << person << " joined the line!" << endl;
    }
}

void remove_person(int line[LINE_LENGTH], int* people_amount) {
    if (*people_amount > 0) {
        cout << "Person " << line[0] << " got their lunch!" << endl;

        for (int i = 0; i < *people_amount - 1; i++) {
            line[i] = line[i + 1];
        }
        *people_amount -= 1;
    }
}
