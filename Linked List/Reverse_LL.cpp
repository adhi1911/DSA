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
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head; 
        ListNode* q = nullptr;
        ListNode* r = nullptr; 

        while(p){
            r = q;
            q = p;
            p = p->next;
            q->next=r;
        }
    return q;
    }
};


/*

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        p = head 
        q,r = None, None
        while(p):
            r = p.next 
            p.next = q
            q = p 
            p = r
        
        return q
        
*/