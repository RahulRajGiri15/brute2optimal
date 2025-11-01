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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st(begin(nums) , end(nums));

        ListNode* temp = head;
        ListNode* newList = new ListNode(-1);
        ListNode* newhead = newList;
        while(temp != NULL){
            if(st.count(temp->val) == false){
                newList->next = new ListNode(temp->val);
                newList = newList->next;
            }
            temp = temp->next;
        }
        return newhead->next;
    }
};