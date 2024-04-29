//{ Driver Code Starts
import java.util.*;
import java.io.*;

class Node{
    int data;
    Node next;
    
    Node(int x){
        data = x;
        next = null;
    }
    
}
class GFG{
	static void printList(Node node) 
	{ 
		while (node != null) 
		{ 
			System.out.print(node.data + " "); 
			node = node.next; 
		} 
		System.out.println(); 
	}
    public static void main(String args[]) throws IOException { 
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t > 0){
        	int n = sc.nextInt();
            Node head = new Node(sc.nextInt());
            Node tail = head;
            for(int i=0; i<n-1; i++)
            {
                tail.next = new Node(sc.nextInt());
                tail = tail.next;
            }
            Solution g = new Solution();
            head = g.deleteMid(head);
            printList(head); 
            t--;
        }
    } 
} 
   

// } Driver Code Ends



/*
class Node {
    int data;
    Node next;
    Node(int d)  { data = d;  next = null; }
}
*/

class Solution {
    int count(Node head){
        int c=0;
        while(head!=null){
            c++;
            head=head.next;
        }
        return c;
    }
    Node deleteMid(Node head) {

        if(head==null) return head;
        int c = count(head);
         if(c==1) return null;
        int p = c/2;
            Node ptr = head;
            Node pre = null;
            while(p>=1){
                pre=ptr;
              ptr=ptr.next;
              p--;
            }
            pre.next=ptr.next;
            ptr.next = null;  
            
        return head;
    }
}



