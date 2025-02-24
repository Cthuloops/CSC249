/**
 * CSC-249
 * M3T1 - Singly linked list
 * Harley Coughlin
 * 02/24/2025
 */


#include <iostream>
#include "./SinglyLinkedList.hpp"

using namespace std;


int main() {
    LinkedList num_list;
    Node* node_a = new Node(1010);
    Node* node_b = new Node(4);
    Node* node_c = new Node(2);
    Node* node_d = new Node(0);
    Node* node_e = new Node(69);
    Node* node_f = new Node(17);

    // Append nodes.
    num_list.append(node_b);
    num_list.append(node_c);
    num_list.append(node_e);

    // Make node_a the head.
    num_list.prepend(node_a);

    // Insert after
    num_list.insert_after(node_c, node_d);
    num_list.insert_after(node_e, node_f);

    // Print the list
    cout << "List after adding nodes: ";
    num_list.print(cout);

    // Remove the tail and head.
    num_list.remove_after(node_e);
    num_list.remove_after(nullptr);

    // Output the final list.
    cout << "List after removing nodes: ";
    num_list.print(cout);

    return 0;
}
