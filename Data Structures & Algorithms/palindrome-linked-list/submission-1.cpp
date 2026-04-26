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

    ListNode* findMiddle(ListNode* head)
    {
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head, *prev = NULL, *next = NULL;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid = findMiddle(head);
        ListNode* revHead = reverse(mid->next);

        ListNode* curr2=revHead, *curr1 = head;
        
        while(curr1 && curr2)
        {
            if(curr1->val != curr2->val)
            {
                return false;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return true;
    }
};