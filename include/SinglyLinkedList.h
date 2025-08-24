#include "ListNode.h"

class SinglyLinkedList {
    public:
        SinglyLinkedList();
        ~SinglyLinkedList();

        void insert(std::string value);
        void insert(std::string value, int index);
        ListNode* getNode(int index);
        void deleteNode(int index);
        void print(std::ostream& os);
        int getSize();
        void clearData(int index);
    private:
        ListNode* head;
        ListNode* tail;
        int size;
};