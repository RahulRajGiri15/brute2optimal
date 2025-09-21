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
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = reverse(l1);
        // l2 = reverse(l2);
        int carry =0;
        ListNode* dummy = new ListNode(0);
        ListNode* result = dummy;
        int sum =0;
        while(l1 || l2 || carry){
            sum = carry;
            if(l1 != NULL){
                sum += l1 ->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            //ListNode* dummy = new ListNode(sum %10);
            result->next = new ListNode(sum %10);
            result = result->next;
            carry = sum /10;
            
            sum = 0;
        }
        if(carry != 0){
            result->next = new ListNode(carry);
        }
        return dummy->next;
    }
};