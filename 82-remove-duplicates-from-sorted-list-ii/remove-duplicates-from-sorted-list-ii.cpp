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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
       ListNode* dummy = new  ListNode(0);  
       ListNode* prev = dummy;
        ListNode* curr = head;
        dummy->next = head;
        while(curr->next!=nullptr)
        {
          if(curr->val ==curr->next->val)
          {
            int num = curr->val;
            while(curr!=nullptr&&curr->val ==num)
            {
                curr = curr->next;
            }
           if(curr)
           { prev->next = curr;
            
           }
           else
           {
            prev->next = nullptr;
            return dummy->next;
           }
          }
          else
        {
            prev = prev->next;
            curr = curr->next;
        }
        }
   return dummy->next;
    }
};