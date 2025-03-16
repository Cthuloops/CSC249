#include <iostream>
#include "iQueue.hpp"


class ArrayQueue : public iQueue {
 private:
    int allocation_size;
    int* array;
    int front_index;
    int length;
    int max_length;

    void resize() {
        int new_size = allocation_size * 2;
        if (max_length >= 0 && new_size > max_length) {
            new_size = max_length;
        }

        int* new_array = new int[new_size];
        for (int i = 0; i < length; i++) {
            int item_index = (front_index + i) % allocation_size;
            new_array[i] = array[item_index];
        }

        delete[] array;
        array = new_array;
        allocation_size = new_size;

        front_index = 0;
    }

 public:
    ArrayQueue(int maximum_length = -1) {
        allocation_size = (0 == maximum_length) ? 0 : 1;
        array = new int[allocation_size];
        length = 0;
        front_index = 0;
        max_length = maximum_length;
    }

    virtual ~ArrayQueue() {
        delete[] array;
    }

    bool enqueue(int item) override {
        // If at max_length, return false.
        if (length == max_length) {
            return false;
        }

        // Resize if length equals allocation size.
        if (length == allocation_size) {
            resize();
        }
        
        // Enqueue the item and return true.
        int item_index = (front_index + length) % allocation_size;
        array[item_index] = item;
        length++;
        return true;
    }

    int dequeue() override {
        // Get the item from the front of the queue.
        int to_return = array[front_index];

        // Decrement length and advance front_index.
        length--;
        front_index = (front_index + 1) % allocation_size;

        return to_return;
    }

    int peek() const override {
        return array[front_index];
    }

    bool is_empty() const override {
        return length == 0;
    }

    int get_length() const override {
        return length;
    }

    int get_max_length() {
        return max_length;
    }

    void print(std::ostream& print_stream = std::cout,
               const std::string& separator = ", ") const override {
        int index = front_index;
        // Print first item and advance the index.
        print_stream << array[index];
        index = (index + 1) % allocation_size;

        // Print the rest.
        for (int i = 1; i < length; ++i) {
            print_stream << separator << array[index];
            index = (index + 1) % allocation_size;
        }
    }
};
