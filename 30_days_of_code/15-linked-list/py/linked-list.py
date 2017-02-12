class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
class Solution:
    def display(self,head):
        current = head
        while current:
            print current.data,
            current = current.next

    def insert(self,head,data):
        if head == None:
            return Node(data)
        else:
            tail_node = self.tail(head)
            tail_node.next = Node(data)
            return head

    def tail(self, head):
        cursor = head
        while cursor.next:
            cursor = cursor.next
        return cursor

mylist= Solution()
T=int(input())
head=None
for i in range(T):
    data=int(input())
    head=mylist.insert(head, data)
mylist.display(head);
