/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* rev(ListNode* node){
        if(!node || !node->next) return node;
        ListNode* prev = nullptr, *cur = node, *nxt = nullptr;
        while(cur){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* nxt = slow->next;
        slow->next = nullptr;
        nxt = rev(nxt);
        ListNode* cur = head;
        while (cur && nxt) {
            ListNode* t1 = cur->next;
            ListNode* t2 = nxt->next;

            cur->next = nxt;
            nxt->next = t1;

            cur = t1;
            nxt = t2;
        }
    }
};
