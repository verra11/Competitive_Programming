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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* mid;
        mid = head;
        while(head!=NULL && head->next!=NULL)
        {
        	mid=mid->next;
        	head=head->next;
        	if(head!=NULL)
        		head=head->next;
        }
        return mid;
    }
};