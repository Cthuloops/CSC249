#ifndef MOD3_L_ARRAYSTACK_HPP_
#define MOD3_L_ARRAYSTACK_HPP_

#include <iostream>
#include "./iStack.hpp"


class ArrayStack : public iStack {
 private:
    int allocation_size;
    int* array;
    int length;
    int max_length;

    // What's a vector?
    void resize() {
        int new_size = allocation_size * 2;
        int* new_array = new int[new_size];

        // Copy elements from old array to new array
        for (int i = 0; i < length; i++) {
            new_array[i] = array[i];
        }

        delete[] array;
        array = new_array;
        allocation_size = new_size;
    }

 public:
    ArrayStack(int optional_max_length = -1) {
        allocation_size = 1;
        array = new int[allocation_size];
        length = 0;
        max_length = optional_max_length;
    }

    virtual ~ArrayStack() {
        delete[] array;
    }

    virtual int get_length() const override {
        return length;
    }

    virtual int get_max_length() const {
        return max_length;
    }

    virtual bool is_empty() const override {
        return length == 0;
    }

    virtual int peek() const override {
        return array[length - 1];
    }

    virtual int pop() override {
        return array[--length];
    }

    virtual void print(std::ostream& print_stream = std::cout,
                       const std::string& separator = ", ") const override {
        if (length > 0) {
            print_stream << array[length - 1];
        }

        for (int i = length - 2; i >= 0; i--) {
            print_stream << separator << array[i];
        }
    }

    virtual bool push(int item) override {
        if (length == max_length) {
            return false;
        }

        if (length == allocation_size) {
            resize();
        }

        array[length] = item;
        length++;
        return true;
    }
};

#endif  // MOD3_L_ARRAYSTACK_HPP_
