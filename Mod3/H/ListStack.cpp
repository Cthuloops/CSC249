// Stack using a signly linked list

#include "iStack.hpp"
#include "SinglyLinkedList.hpp"


class ListStack : public iStack {
 private:
    LinkedList list;

 public:
    ListStack() {
    }

    bool push(int item) override {
        Node* new_node = new Node(item);
        list.prepend(new_node);
        return true;
    }

    int pop() override {
        int popped = list.get_head()->data;
        list.remove_after(nullptr);
        return popped;
    }

    int get_length() const override {
        return list.get_length();
    }

    bool is_empty() const override {
        return list.get_length() == 0;
    }

    int peek() const override {
        return list.get_head()->data;
    }

    void print(std::ostream& print_stream = std::cout,
               const std::string& separator = ", ") const override {
        list.print(print_stream, separator);
    }

};
