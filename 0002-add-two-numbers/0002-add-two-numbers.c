/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    // Dummy node to make result list creation easier
    struct ListNode dummy;
    dummy.next = NULL;
    
    struct ListNode* current = &dummy;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry != 0) {
        
        int sum = carry;
        
        // Add value from l1
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        // Add value from l2
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        // Calculate carry
        carry = sum / 10;
        
        // Create new node for current digit
        struct ListNode* newNode = 
            (struct ListNode*)malloc(sizeof(struct ListNode));
        
        newNode->val = sum % 10;
        newNode->next = NULL;
        
        current->next = newNode;
        current = newNode;
    }
    
    return dummy.next;
}