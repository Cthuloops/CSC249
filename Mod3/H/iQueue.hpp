#ifndef MOD3_H_IQUEUE_HPP_
#define MOD3_H_IQUEUE_HPP_

#include <iostream>
#include <string>

class iQueue {
 public:
    virtual bool enqueue(int item) = 0;
    virtual int dequeue() = 0;

    virtual int peek() const = 0;
    virtual bool is_empty() const = 0;
    virtual int get_length() const = 0;
    virtual void print(std::ostream& print_stream = std::cout,
                       const std::string& separator = ", ") const = 0;
};

#endif  // MOD3_H_IQUEUE_HPP_
