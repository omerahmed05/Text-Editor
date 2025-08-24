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
    ListNode* curr = head;

    while (curr) {
        ListNode* next = curr->next;
        delete curr;
        curr = next;
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

ListNode* SinglyLinkedList::getNode(int index) {
    if (index < 0 || index >= size) {
        return nullptr;
    }
    ListNode* curr = head;

    int i = 0;

    while (i < index && curr != nullptr) {
        curr = curr->next;
        i++;
    }

    return curr;
}

/**
 * Delete the node at the index
 */
void SinglyLinkedList::deleteNode(int index) {
    ListNode* curr = head;
    int i = 0;

    if (index == 0) {
        curr = curr->next;
        delete head;
        head = curr;
        size--;
        return;
    }
    while (i < index - 1 && curr != nullptr) {
        curr = curr->next;
        i++;
    }

    if (curr && curr->next) {
        ListNode* currNext = curr->next;
        curr->next= curr->next->next;
        delete currNext;
        size--; 
    }
}

/**
 * Print the current linked list
 */
void SinglyLinkedList::print(std::ostream& os) {
    ListNode* curr = head;
    for (int i = 0; i < size; i++) {
        os << i+1 << ": " << curr->value << "\n";
        curr = curr->next;
    }
}

int SinglyLinkedList::getSize() {
    return size;
}

void SinglyLinkedList::clearData(int index) {
    ListNode* curr = head;

    int i = 0;
    while (curr && i < index) {
        curr = curr->next;
        i++;
    }

    if (curr != nullptr) {
        curr->value = "";
    }
}