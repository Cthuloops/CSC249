/**
 * CSC-249
 * M3L1 - ArrayStack
 * Harley Coughlin
 * 03/10/2025
 */

#include "./ArrayStack.hpp"

using namespace std;

int main() {
    ArrayStack bounded_stack(4);
    ArrayStack unbounded_stack;

    cout << "Pushing values 1 through 8 to each stack" << endl;
    for (int i = 1; i <= 8; i++) {
        bounded_stack.push(i);
        unbounded_stack.push(i);
    }

    // Pop twice
    cout << "Popping twice" << endl;
    for (int i = 0; i < 2; i++) {
        bounded_stack.pop();
        unbounded_stack.pop();
    }

    // Push 4 more items to each stack
    cout << "Pushing values to each stack: 10, 20, 30, and 40" << endl;
    for (int i = 0; i <= 40; i += 10) {
        bounded_stack.push(i);
        unbounded_stack.push(i);
    }


    // Display each stack
    cout << "Bounded stack (max_length=" << bounded_stack.get_max_length()
         << ") contents: " << endl;
    bounded_stack.print();
    cout << endl;
    cout << "Unbounded stack (max_length=" << unbounded_stack.get_max_length()
         << ") contents: " << endl;
    unbounded_stack.print();
    cout << endl;

    return 0;
}
