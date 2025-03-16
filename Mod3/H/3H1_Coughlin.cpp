/**
 * CSC-249
 * 3H1 - Stacks and Queues in Practice
 * Harley Coughlin
 * 03/16/2025
 */

#include <iostream>
#include "./ArrayQueue.cpp"
#include "./ListQueue.cpp"
#include "./ListStack.cpp"

using namespace std;


int main() {

    // ArrayQueues
    ArrayQueue arr_bounded_queue(4);
    ArrayQueue arr_unbounded_queue;
    ListQueue list_queue;
    ListStack list_stack;

    // Enqueue values
    cout << "Enqueueing values 1 through 8 to each queue\n";
    for (int i = 1; i <= 8; ++i) {
        arr_bounded_queue.enqueue(i);
        arr_unbounded_queue.enqueue(i);
        list_queue.enqueue(i);
    }

    // Push to the Stack
    cout << "Stacking values 1 through 8\n\n";
    for (int i = 1; i <= 8; ++i) {
        list_stack.push(i);
    }

    // Dequeue two items from each queue
    cout << "Dequeuing twice\n";
    for (int i = 0; i < 2; ++i) {
        cout << "  Dequeued " << arr_bounded_queue.dequeue()
             << "  from bounded queue\n";
        cout << "  Dequeued " << arr_unbounded_queue.dequeue()
             << "  from unbounded queue\n";
        cout << "  Dequeued " << list_queue.dequeue()
             << "  from linked list queue\n";
    }

    // Pop two items from the Stack.
    cout << "\nPopping two items\n";
    for (int i = 0; i < 2; ++i) {
        cout << "  Popped " << list_stack.pop() << '\n';
    }

    cout << "\nEnqueueing values: 10, 20, 30, and 40\n";
    for (int i = 10; i <= 40; i += 10) {
        arr_bounded_queue.enqueue(i);
        arr_unbounded_queue.enqueue(i);
        list_queue.enqueue(i);
    }

    cout << "Stacking 10, 20, 30, and 40\n";
    for (int i = 10; i <= 40; i += 10) {
        list_stack.push(i);
    }

    // Display contents of each queue and the stack.
    cout << "\nBounded ArrayQueue (max length=" << arr_bounded_queue.get_max_length()
         << ") contents:\n  ";
    arr_bounded_queue.print();
    cout << '\n';
    cout << "Unbounded ArrayQueue contents:\n  ";
    arr_unbounded_queue.print();
    cout << '\n';
    cout << "ListQueue contents:\n  ";
    list_queue.print();
    cout << "ListStack contents:\n  ";
    list_stack.print();
    cout << endl;

    return 0;
}
