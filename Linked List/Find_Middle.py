# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cnt = 0
        p = head
        ## brute force
        # while p:
        #     p = p.next 
        #     cnt+=1
        # # print(cnt//2)
        # p = head
        # for i in range(cnt//2):
        #     p = p.next

        ## hare and tortoise 
        q = head 
        while p and p.next:
            p = p.next.next 
            q = q.next

        return q
                

