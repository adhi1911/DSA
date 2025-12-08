# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        visited = []
        current = head 
        while current:
            if current in visited:
                return current
            visited.append(current)
            current = current.next

        return None