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
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         if(head == NULL) return head;
//         ListNode* temp = head;
//         int count = 0;
//         while(temp != NULL){
//             temp = temp->next;
//             count++;
//         }
//         int mid = 0;
//         if(count % 2 == 0) mid = count / 2 ;
//         else mid = count /2;

//         for(int i =0;i<mid;i++){
//             head = head->next;
//         }
//         return head;
//     }
// };

//////////////////////////

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};