# your task is to complete this function
# Function should return an integer value

'''
class node:
    def __init__(self):
        self.data = None
        self.next = None
'''

class Solution:
    def reverseList(self,head):
        prev=None
        while head!=None:
            next_node=head.next
            head.next=prev
            prev=head
            head=next_node
        return prev
    def decimalValue(self, head):
        MOD=10**9+7
        new_head=self.reverseList(head)
        i=0
        ans=0
        while new_head!=None:
            ans+=(2**i)*new_head.data
            ans=ans%MOD
            i+=1
            new_head=new_head.next
        return ans%MOD

#{ 
 # Driver Code Starts
# Node Class    
class node:
    def __init__(self):
        self.data = None
        self.next = None
# Linked List Class
class Linked_List:
    def __init__(self):
        self.head = None

    def insert(self, data):
        if self.head == None:
            self.head = node()
            self.head.data = data
        else:
            new_node = node()
            new_node.data = data
            new_node.next = None
            temp = self.head
            while(temp.next):
                temp=temp.next
            temp.next = new_node

# Driver Program
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        list1 = Linked_List()
        n = int(input())
        values = list(map(int, input().strip().split()))
        for i in values:
            list1.insert(i)
        ob=Solution()
        print(ob.decimalValue(list1.head))
# Contributed By: Harshit Sidhwa
# } Driver Code Ends