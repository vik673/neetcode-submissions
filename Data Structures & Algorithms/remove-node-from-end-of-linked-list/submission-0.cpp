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
    int countNode(ListNode* head)
    {
        int count =0;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            curr = curr->next;
            count++;
        }
        return count;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = countNode(head);

        if(len < n) return NULL;
        ListNode* curr = head, *prev = NULL;
        for(int i=0;i<len-n;i++)
        {
           prev = curr;
           curr = curr->next;
        }

        if(prev) prev->next = curr->next;
        else  head= head->next;

        delete curr;

        return head;
    }
};
