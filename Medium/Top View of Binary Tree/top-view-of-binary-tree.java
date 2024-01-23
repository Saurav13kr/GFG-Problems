//{ Driver Code Starts
//Initial Template for JAVA

import java.util.LinkedList; 
import java.util.Queue; 
import java.io.*;
import java.util.*;

class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}

public class Tree {
    
    static Node buildTree(String str){
        
        if(str.length()==0 || str.charAt(0)=='N'){
            return null;
        }
        
        String ip[] = str.split(" ");
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Push the root to the queue
        
        Queue<Node> queue = new LinkedList<>(); 
        
        queue.add(root);
        // Starting from the second element
        
        int i = 1;
        while(queue.size()>0 && i < ip.length) {
            
            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();
                
            // Get the current node's value from the string
            String currVal = ip[i];
                
            // If the left child is not null
            if(!currVal.equals("N")) {
                    
                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }
                
            // For the right child
            i++;
            if(i >= ip.length)
                break;
                
            currVal = ip[i];
                
            // If the right child is not null
            if(!currVal.equals("N")) {
                    
                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));
                    
                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }
        
        return root;
    }
    static void printInorder(Node root)
    {
        if(root == null)
            return;
            
        printInorder(root.left);
        System.out.print(root.data+" ");
        
        printInorder(root.right);
    }
    
	public static void main (String[] args) throws IOException{
	        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	        
	        int t=Integer.parseInt(br.readLine());
    
	        while(t > 0){
	            String s = br.readLine();
    	    	Node root = buildTree(s);
    	    	
                Solution ob = new Solution();

                ArrayList<Integer> vec = ob.topView(root);
                for(int x : vec)
                    System.out.print(x + " ");
                System.out.println();
        	
                t--;   
        }
    }
}
// } Driver Code Ends


//User function Template for Java

/*
class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}
*/

class Solution
{
    static class pair{
        Node n;
        int hd;
        pair(Node n,int hd){
            this.n=n;
            this.hd=hd;
        }
    }
    static ArrayList<Integer> topView(Node root){
        ArrayList<Integer> arr=new ArrayList<>();
        if(root==null){
            return arr;
        }
        HashMap<Integer,Node> m=new HashMap<>();
        Queue<pair> q=new ArrayDeque<>();
        pair a=new pair(root,0);
        q.add(a);
        int max=0,min=0;
        while(!q.isEmpty()){
            int size=q.size();
            while(size>0){
                pair curr=q.poll();
                if(!m.containsKey(curr.hd)){
                    m.put(curr.hd,curr.n);
                    max=Math.max(curr.hd,max);
                    min=Math.min(curr.hd,min);
                }
                if(curr.n.left!=null){
                    pair b=new pair(curr.n.left,curr.hd-1);
                    q.add(b);
                }
                if(curr.n.right!=null){
                    pair c=new pair(curr.n.right,curr.hd+1);
                    q.add(c);
                }
                size--;
            }
        }
        while(min!=0){
            Node c=m.get(min);
            arr.add(c.data);
            min++;
        }
        int i=0;
        while(i<=max){
            Node c=m.get(i);
            arr.add(c.data);
            i++;
        }
        return arr;
    }
}


