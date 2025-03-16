#include "./iQueue.hpp"
#include "./SinglyLinkedList.hpp"

class ListQueue : public iQueue {
 private:
    LinkedList list;

 public:
    ListQueue() {}

    bool enqueue(int item) override {
        Node* new_node = new Node(item);
        list.append(new_node);
        return true;
    }

    int dequeue() override {
        int dequeued = list.get_head()->data;
        list.remove_after(nullptr);
        return dequeued;
    }

    int peek() const override {
        return list.get_head()->data;
    }

    bool is_empty() const override {
        return list.get_length() == 0;
    }

    int get_length() const override {
        return list.get_length();
    }

    void print(std::ostream& print_stream = std::cout,
               const std::string& separator = ", ") const override {
        list.print(print_stream, separator);
    }
};
