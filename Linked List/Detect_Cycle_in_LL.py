# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


## Brute Force Approach
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        visited = set()
        current = head 
        while current:
            if current in visited:
                return True 
            visited.add(current)
            current = current.next

        return False