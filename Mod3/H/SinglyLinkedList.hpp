#ifndef MOD3_SINGLYLINKEDLIST_HPP_
#define MOD3_SINGLYLINKEDLIST_HPP_

/**
 * CSC-249
 * M3.T1 - Singly Linked List
 * Harley Coughlin
 * 02/24/2025
 */


#include <iostream>
#include <string>

using namespace std;


class Node {
 public:
    int data;
    Node* next;

    explicit Node(int initial_data) : data(initial_data), next(nullptr) {}
};


class LinkedList {
 private:
    Node* head;
    Node* tail;
    int length;

 public:
    // Default constructor
    LinkedList() : head(nullptr), tail(nullptr), length(0) {}

    // Destructor
    virtual ~LinkedList() {
        Node* current_node = head;
        while (current_node) {
            Node* to_delete = current_node;
            current_node = current_node->next;
            delete to_delete;
        }
    }

    void append(Node* new_node) {
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        length++;
    }

    void prepend(Node* new_node) {
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }
        length++;
    }

    void insert_after(Node* current_node, Node* new_node) {
        // Handle empty list.
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else if (current_node == tail) {
            tail->next = new_node;
            tail = new_node;
        } else {
            new_node->next = current_node->next;
            current_node->next = new_node;
        }
        length++;
    }

    void remove_after(Node* current_node) {
        // Special case, remove head.
        if (current_node == nullptr && head) {
            Node* to_delete = head;
            head = head->next;
            delete to_delete;

            // Check if last item was removed.
            if (head == nullptr) {
                tail = nullptr;
            }
        } else if (current_node->next) {
            Node* to_delete = current_node->next;
            current_node->next = to_delete->next;
            delete to_delete;
            if (current_node->next == nullptr) {
                tail = current_node;
            }
        }
        length--;
    }

    int get_length() const {
        return length;
    };

    Node* get_head() const {
        return head;
    };

    void print(ostream& print_stream = std::cout, const string& separator = ", ") const {
        Node* node = head;
        if (node) {
            // Head node not preceded by separator
            print_stream << node->data;
            node = node->next;
        }
        while (node) {
            print_stream << separator << node->data;
            node = node->next;
        }
        print_stream << endl;
    }
};

#endif  // MOD3_SINGLYLINKEDLIST_HPP_
