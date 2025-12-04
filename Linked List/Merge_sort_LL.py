# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode()
        p = head 

        
        while list1 and list2:
            if list1.val < list2.val:
                p.next = ListNode(list1.val)
                p = p.next 
                list1 = list1.next

            elif(list1.val > list2.val):
                p.next = ListNode(list2.val)
                p = p.next 
                list2 = list2.next 
            else:
                p.next = list1
                list1 = list1.next
                p = p.next
                p.next = list2
                list2 = list2.next
                p = p.next

        while list1:
            p.next = ListNode(list1.val)
            p = p.next 
            list1 = list1.next         
        
        while list2:
            p.next = ListNode(list2.val)
            p = p.next 
            list2 = list2.next    

        return head.next      


        