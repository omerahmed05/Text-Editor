#include "SinglyLinkedList.h"
#include <iostream>

/**
 * Constructor
 */
SinglyLinkedList::SinglyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

/**
 * Destructor
 */
SinglyLinkedList::~SinglyLinkedList() {
    for (int i = 0; i < size; i++) {
        deleteNode(i);
    }
}

/**
 * Insert to the end of the linked list
 */
void SinglyLinkedList::insert(std::string value) {
    ListNode* new_node = new ListNode();
    new_node->value = value;

    if (tail == nullptr) {
        head = tail = new_node;
    } 
    else {
        tail->next = new_node;
        tail = tail->next;
    }

    size++;
}

/**
 * Insert in the middle of the linked list at index
 */
void SinglyLinkedList::insert(std::string value, int index) {
    ListNode* new_node = new ListNode();
    new_node->value = value;

    if (index == 0) {
        new_node->next = head;
        head = new_node;

        if (tail == nullptr) {
            tail = head;
        }
    }
    else if (head == nullptr) {
        head = tail = new_node;
    }
    else {
        int i = 0;
        ListNode* curr = head;

        while (curr != nullptr and i < index - 1) {
            curr = curr->next;
            i++;
        }

        if (curr == nullptr) {
            std::cout << "Out of bounds!";
            delete new_node;
            return;
        } 
        else {
            ListNode* temp = curr->next;
            curr->next = new_node;
            new_node->next = temp;

            if (new_node->next == nullptr) {
                tail = new_node;
            }
        }
    }

    size++;
}

/**
 * Delete the node at the index
 */
void SinglyLinkedList::deleteNode(int index) {

}

/**
 * Print the current linked list
 */
void SinglyLinkedList::print() {

}