# Definition for singly-linked list.
from typing import Optional


class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        
        list3 = ListNode(-1)
        temp1 ,temp2 ,temp3= list1 , list2 , list3
        temp4 = list3
        while temp1 and temp2:                         
                if temp1.val < temp2.val:
                    temp3.next = temp1
                    temp1 = temp1.next                    
                else:
                    temp3.next = temp2
                    temp2 = temp2.next
                temp3 = temp3.next
        while temp1:
            temp3.next = temp1
            temp1 = temp1.next
            temp3 = temp3.next
            
        while temp2:
            temp3.next = temp2
            temp2 = temp2.next
            temp3 = temp3.next
        
        return temp4.next