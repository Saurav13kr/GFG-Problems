#User function Template for python3

class Solution:
    def alternatingSplitList(self, head):
        h1=head
        h2=head.next
        ptr1=h1
        ptr2=h2
        res=[h1,h2]
        
        while(ptr2!=None and ptr2.next!=None):
            ptr1.next=ptr2.next
            ptr1=ptr1.next
            ptr2.next=ptr1.next
            ptr2=ptr2.next
        ptr1.next=None
        return res
        
#{ 
 # Driver Code Starts
class Node:

    def __init__(self, x):
        self.data = x
        self.next = None


def printList(node):
    while node is not None:
        print(node.data, end=" ")
        node = node.next
    print()


if __name__ == "__main__":
    t = int(input().strip())

    for _ in range(t):
        arr = list(map(int, input().strip().split()))

        head = Node(arr[0])
        tail = head

        for i in range(1, len(arr)):
            tail.next = Node(arr[i])
            tail = tail.next

        ob = Solution()
        result = ob.alternatingSplitList(head)
        printList(result[0])
        printList(result[1])

# } Driver Code Ends