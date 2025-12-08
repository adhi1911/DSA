# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


## Brute Force Approach
# class Solution:
#     def hasCycle(self, head: Optional[ListNode]) -> bool:
#         visited = set()
#         current = head 
#         while current:
#             if current in visited:
#                 return True 
#             visited.add(current)
#             current = current.next

#         return False

# FLoyd's Cycle-Finding Algorithm 
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next:
            return False 

        slow = head
        fast = head 
        while fast and fast.next:
            slow = slow.next 
            fast = fast.next.next 

            if slow == fast :
                return True 

        return False

# TC: O(N)
# SC: O(1)
## why this works: 
# fast moves two steps ahead and slow only one
# if there is a cycle, fast will be cycled back to the earlier nodes thus behind slow
# so with each iteration the distance between them decreases by 1
# eventually they will meet
# if there is no cycle, fast will reach the end of the list (None) and iteration stops