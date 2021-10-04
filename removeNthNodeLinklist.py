class Node:
    def __init__(self,val):
        self.val = val
        self.next =  None


class LinkList:

    def __init__(self):
        self.head = None

    def addNode(self,node):
        if self.head is None:
            self.head = node
        else:
            temp = self.head

            while temp.next:
                temp= temp.next

            temp.next =  node

    def print(self):
        temp = self.head
        while temp:
            print(temp.val)
            temp = temp.next

    def removeNThNode(self,n):
        dummy = Node(0)
        dummy.next = self.head
        first = dummy
        second = dummy

        #move first by n times
        i = 1
        while i <= n+1:
            first = first.next
            i+=1
		#Move first to end and second will be 2 nodes from last
		#Move next to second to next of next
        while first:
            first = first.next
            second = second.next

        second.next = second.next.next
        return dummy.next


l = LinkList()
n1 = Node(1)
n2 = Node(2)
n3 = Node(3)
n4 = Node(4)
n5 = Node(5)
l.addNode(n1)
l.addNode(n2)
l.addNode(n3)
l.addNode(n4)
l.addNode(n5)
l.print()
l.removeNThNode(2)
l.print()


