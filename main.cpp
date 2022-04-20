#include <iostream>
#include <list>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 아무것도 없음 바로 리턴을 해줌
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode *pNodeA = headA;
        ListNode *pNodeB = headB;

        // listA-listB, listB-listA 순으로 비교하면 동일한 노드 발견 가능
        while (pNodeA != pNodeB) {
            if (pNodeA == nullptr) {
                pNodeA = headB;
            }else{
                pNodeA = pNodeA->next;
            }

            if (pNodeB == nullptr) {
                pNodeB = headA;
            } else {
                pNodeB = pNodeB->next;
            }
        }

        return pNodeA;

    }

};

int main() {

    ListNode a0(4);
    ListNode a1(1);
    ListNode a2(8);
    ListNode a3(4);
    ListNode a4(5);
    a0.next = &a1;
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = nullptr;

    ListNode b0(5);
    ListNode b1(6);
    ListNode b2(1);
    ListNode b3(8);
    ListNode b4(4);
    ListNode b5(5);

    b0.next = &b1;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &b4;
    b4.next = &b5;
    b5.next = nullptr;

    Solution sol;
    auto node = sol.getIntersectionNode(&a0, &b0);

    cout << node->val << endl;

    return 0;
}
