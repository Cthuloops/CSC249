#ifndef MOD3_L_ISTACK_HPP_
#define MOD3_L_ISTACK_HPP_

#include <iostream>
#include <string>


class iStack {
 public:
    virtual bool push(int item) = 0;
    virtual int pop() = 0;

    virtual int get_length() const = 0;
    virtual bool is_empty() const = 0;
    virtual int peek() const = 0;
    virtual void print(std::ostream& print_stream = std::cout,
                       const std::string& separator = ", ") const = 0;
};

#endif  // MOD3_L_ISTACK_HPP_
