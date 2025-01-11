class Solution {
private:
    ListNode* head;
    
public:
    Solution(ListNode* head) {
        this->head = head;
        std::srand(std::time(0)); 
    }
    
    int getRandom() {
        int count = 0;
        int result = 0;
        ListNode* curr = head;
        
        while (curr) {
            count++;

            if (std::rand() % count == 0) {
                result = curr->val;
            }
            curr = curr->next;
        }
        
        return result;
    }
};