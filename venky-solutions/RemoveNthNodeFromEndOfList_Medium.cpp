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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //empty input head
        if(head == nullptr)
            return nullptr;
        
        //bad value for n
        if(n == 0)
            return head;
        
        ListNode* temp = head;
        ListNode* nthNode = nullptr;
        ListNode* prev = nullptr;
        int count = 0;
        while(temp!=nullptr)
        {
            count++;
            if(count == n)
            {
                nthNode = head;
            }
            else if(count > n)
            {
                prev = nthNode;
                nthNode = nthNode->next;
            }
            temp = temp->next;
        }
        
        if(nthNode != nullptr)
        {
            if(prev == nullptr)
                return nthNode->next;
            else
            {
                prev->next = nthNode->next;
                //free nthNode?
            }
        }
        return head;
    }
};
