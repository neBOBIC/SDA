
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA;
    ListNode *b = headB;

    while (a != b) {
        if (a == nullptr) {
            a = headB;
        } else {
            a = a->next;
        }

        if (b == nullptr) {
            b = headA;
        } else {
            b = b->next;
        }
    }

    return a;
}

int main() {
    // Shared part of the lists
    ListNode *node8 = new ListNode(8);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);

    node8->next = node4;
    node4->next = node5;

    // List A: 4 -> 1 -> 8 -> 4 -> 5
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = node8;

    // List B: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = node8;

    ListNode *result = getIntersectionNode(headA, headB);

    if (result != nullptr) {
        cout << "Intersected at: " << result->val << endl;
    } else {
        cout << "No intersection" << endl;
    }

    return 0;
}
