//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;
    Node prev;

    Node(int x) 
    {
        data = x;
        next = null;
        prev = null;
    }

    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            Node head = null;
            Node tail = head;

            for (int i = 0; i < n; i++) {
                int temp = sc.nextInt();
                if (head == null) {
                    head = new Node(temp);
                    tail = head;
                } else {
                    Node newNode = new Node(temp);
                    tail.next = newNode;
                    newNode.prev = tail;
                    tail = newNode;
                }
            }
            int x = sc.nextInt();

            Solution obj = new Solution();
            Node res = obj.deleteNode(head, x);

            Node.printList(res);
        }
    }
}

// } Driver Code Ends


/*

Definition for doubly Link List Node
class Node
{
    int data;
    Node next;
    Node prev;
    Node(int x){
        data = x;
        next = null;
        prev = null;
    }
}
*/


class Solution {
    public Node deleteNode(Node head, int x)
    {
        if(x == 1){
            if(head.next == null){
                return null;
            }
            head = head.next;
            head.prev = null;
        }
        else{
            Node current = head;
            Node previous = null;
            
            int count = 1;
            while(count <= x-1){
                previous = current;
                current = current.next;
                count++;
            }
            previous.next = current.next;
            if(current.next == null){
                return head;
            }
            current.next.prev = previous;
            
        }
        return head;
    }
}


