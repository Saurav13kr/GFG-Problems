//{ Driver Code Starts
/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;
    
    public Node (int data){
        this.data = data;
        this.next = null;
    }
}

class GFG {
    static void printList(Node node) 
	{ 
		while (node != null) 
		{ 
			System.out.print(node.data + " "); 
			node = node.next; 
		} 
		System.out.println(); 
	}
	public static void main (String[] args) {
		Scanner sc  = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
		    int n = sc.nextInt();
		    
		    Node head = new Node(sc.nextInt());
		    Node tail = head;
		    
		    for(int i=1; i<n; i++){
		        tail.next = new Node(sc.nextInt());
		        tail = tail.next;
		    }
		    Solution obj = new Solution();
		    head = obj.sort(head);
		    printList(head);
		}
	}
}

// } Driver Code Ends



/*
class Node {
    int data;
    Node next;
    
    public Node (int data){
        this.data = data;
        this.next = null;
    }
}
*/

class Solution {
    Node reverse(Node head){
        Node prev = null;
        Node curr = head;
        Node nxt = curr.next;
        while(nxt != null){
            curr.next = prev;
            prev = curr;
            curr = nxt;
            nxt = curr.next;
        }
        curr.next = prev;
        return curr;
    }
   public Node sort(Node head){
       if(head == null) return head;
       Node temp = head;
       Node main = temp;
       Node tempmain = main;
       if(temp.next == null) return head;
       temp = temp.next;
       Node second = temp;
       Node tempsecond = second;
       if(temp.next == null) return head;
       temp = temp.next;
       Boolean alternate = true;
       while(temp != null){
           if(alternate){
               alternate = false;
               tempmain.next = temp;
               tempmain = tempmain.next;
           }
           else{
               alternate = true;
               tempsecond.next = temp;
               tempsecond = tempsecond.next;
           }
           temp = temp.next;
       }
       tempmain.next = null;
       tempsecond.next = null;
       Node reversed = reverse(second); 
       Node sorted = new Node(0);
       temp = sorted;
       while(reversed != null || main != null){
           if(reversed == null){
               temp.next = main;
               return sorted.next;
           }
           else if(main == null){
               temp.next = reversed;
               return sorted.next;
           }
           else{
               if(main.data < reversed.data){
                   temp.next = main;
                   main = main.next;
                   temp = temp.next;
               }
               else{
                   temp.next = reversed;
                   reversed = reversed.next;
                   temp = temp.next;
               }
           }
       }
       return sorted.next;
   }
}