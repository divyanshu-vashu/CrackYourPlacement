 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true; // Base case: empty or single node list is always palindrome
        
        // Step 1: Find the middle of the list using two pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        // Step 3: Compare the first and second half
        ListNode* first = head;
        ListNode* second = prev;  // `prev` is now the head of the reversed second half
        while (second != nullptr) { // Compare until the second half is exhausted
            if (first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }
        
        return true;
    }
};
