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
    int getGCD(int a, int b)
    {
        if(a>b) swap(a,b);

        while(b!=0)
        {
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr= head, *prev= NULL;
        int first=0;
        int second=0;

        while(curr && curr->next)
        {
            prev = curr;
            curr = curr->next;   
            first = prev->val;
            second = curr->val;

            int gcd = getGCD(first, second);

            ListNode* temp = new ListNode(gcd);
            temp->next = curr;
            prev->next = temp; 
        }
        return head;
    }
};