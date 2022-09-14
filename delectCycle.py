class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slowPointer = head
        fastPointer = head
        flag = 0
        while slowPointer and fastPointer and fastPointer.next:
            slowPointer = slowPointer.next
            fastPointer = fastPointer.next.next            
            if slowPointer == fastPointer:
                flag = 1
                break
        if flag == 0:
           return None            
        
        slowPointer = head
        while slowPointer!=fastPointer:
              slowPointer = slowPointer.next
              fastPointer = fastPointer.next
            
        return slowPointer