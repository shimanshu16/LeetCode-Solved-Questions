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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       ListNode* c = new ListNode(100);
        ListNode* temp = c;

        while(list1!=nullptr && list2!=nullptr){
            if(list1->val <= list2->val){
                temp->next = list1;
                list1=list1->next;
                temp = temp->next;
               
            }
            else{
                // if b is less then a
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
               
            }
        }
            // now for remaning elements
            // if a = null 
            if(list1==nullptr) temp->next =list2;
            else temp->next = list1;
            return c->next;  
    }
};