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
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head, *prev = NULL, *next = NULL;
        while(curr!= NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* curr1 = l1, *curr2 = l2;
        int sum =0, carry =0;
        ListNode* head = NULL, *tail = NULL;
        while(curr1 || curr2 || carry)
        {
            sum = carry;

            if(curr1) {sum += curr1->val; curr1 = curr1->next;}
            if(curr2) {sum += curr2->val; curr2 = curr2->next;}
            
            carry = sum /10;
            sum = sum %10;
            
            ListNode* temp = new ListNode(sum);

            if(!head){ head = tail = temp;}
            else
            {
                tail->next = temp;
                tail = tail->next;
            }
            sum =0;
        }
        return head;
    }
};
