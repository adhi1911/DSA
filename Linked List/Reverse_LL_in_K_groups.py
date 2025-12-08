# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def revGroup(self, start: Optional[ListNode], k : int, tail: Optional[ListNode]):
        p = start
        q = None 
        r = None 
        for i in range(k) :
            r = p.next 
            p.next = q 
            q = p 
            p = r 
        if tail:
            tail.next = q
        return r

    def hasKNode(self,start: Optional[ListNode], k):
        count = 0 
        current = start 
        while current and count < k: 
            current = current.next
            count += 1
        return count == k

    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head 
        tail = dummy
        start = head

        while start:
            if self.hasKNode(start, k):
                next_group = self.revGroup(start, k , tail)
                # print(next_group.val, start.val, tail.val)
                tail = start 
                start = next_group

            else:
                tail.next = next_group
                break

        return dummy.next


# TC: O(N)
# SC: O(1)
## Approach: 
# consider a list 1->2->3->4->5->6->7->8->9->10 and k = 3

## consider reversing first 3 elements with p,q,r approach
# at the end of reversal we have 3->2->1->4->5->6->7->8->9->10 and 
# p = 4, r = 4, and q = 3 
# so p and r stand at starting element of next group to be reversed (and potential value of tail after reversal)
# and q stands at the head of the reversed group
# we can use this to iteratively reverse the linked list in k groups

# we create a dummy node pointing to head  
# initialize tail = dummy and start = head
# for first group, we reverse k nodes starting from start and tail as dummy so we get dummy->3->2->1->4->5->6->7->8->9->10
# after reversal, we update tail = start (which is 1 now) and start = p (which is 4 now)
# we repeat this process until we reach end of linked list or less than k nodes are remaining
# at the end when nodes less than k are remaining (dymmy->3->2->1->6->5->4->9->8->7  also 9->10 are remaining)
# from last iteration we already have 10 as our next_group start so tail stands on 7 (last node of reversed list)
# we simply do tail.next = next_group to connect the remaining nodes as it is

# TC: O(N)
# SC: O(1)

## Algo 
# 1. Create a dummy node pointing to head
# 2. Initialize tail = dummy and start = head
# 3. While start is not None:
#    a. Check if there are at least k nodes remaining using hasKNode function
#    b. If yes, reverse k nodes starting from start using revGroup function
#       i. Update tail to start (which is now the last node of the reversed group)
#       ii. Update start to next_group (the start of the next group to be processed)
#    c. If no, connect the remaining nodes as they are and break the loop
# 4. Return dummy.next as the new head of the modified list