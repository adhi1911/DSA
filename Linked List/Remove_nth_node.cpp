// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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

// fast and slow pointer approach
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* f = head;
        ListNode* s = head;

        for(int i =0; i<n; i++){
            f = f->next;
        }

        if(!f){
            // we gotta remove head 
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }

        while(f->next){
            f = f->next;
            s = s->next;
        }
        
        ListNode* target = s->next;
        s->next = target->next;
        delete target;
        return head;

    }
};


 //// BRUTE FORCE APPROACH
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* p = head; 
//         int cnt = 0;
//         while(p){
//             cnt +=1;
//             p = p->next;
//         }

//         if(cnt == n){
//             ListNode* newhead = head->next;
//             delete head; 
//             return newhead;
//         }

//         p = head;
//         for(int i =0; i< cnt -n -1; i++){
//             p = p->next;
//         }
//         ListNode* target = p->next;
//         p->next = target->next;
//         delete target;

//         return head;

//     }
// };