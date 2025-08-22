#include "ListNode.h"

class SinglyLinkedList {
    public:
        SinglyLinkedList();
        ~SinglyLinkedList();

        void insert(std::string value);
        void insert(std::string value, int index);
        void deleteNode(int index);
        void print();
        
    private:
        ListNode* head;
        ListNode* tail;
        int size;
};