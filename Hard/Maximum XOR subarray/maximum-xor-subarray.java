//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            int N = Integer.parseInt(read.readLine());
            String input_line[] = read.readLine().trim().split("\\s+");
            int arr[]= new int[N];
            for(int i = 0; i < N; i++)
                arr[i] = Integer.parseInt(input_line[i]);
            

            Solution ob = new Solution();
            
            System.out.println(ob.maxSubarrayXOR(N,arr));
            
            
        }
    }
}

// } Driver Code Ends

class Solution{
    static class Node{
        Node left;
        Node right;
    }

    static int maxSubarrayXOR(int N, int arr[]){
        // code here
        Node root=new Node();
        int[] nums=new int[N+1];
        
        nums[0]=0;
        int xor=0;
        int j=1;
        for(int i=0;i<N;i++){
            int temp=arr[i]^xor;
            nums[j]=temp;
            xor=temp;
            j++;
        }
        
        int maxi=-1;
        for(int i=0;i<=N;i++){
            maxi=Math.max(maxi,nums[i]);
        }
        
        int highestBit=-1;
        for(int i=31;i>=0;i--){
            if((maxi & 1<<i)!=0){
                highestBit=i;
                break;
            }
        }
        
        for(int i=0;i<=N;i++){
            insert(root,nums[i],highestBit);
        }
        
        int ans=-1;
        for(int i=0;i<=N;i++){
            int temp=nums[i]^getMaxXor(root,nums[i],highestBit);
            ans=Math.max(ans,temp);
        }
        
        return ans;
    }
    
    public static void insert(Node root, int num, int n){
        Node t=root;
        
        for(int i=n;i>=0;i--){
            if((num & 1<<i)!=0){
                if(t.right==null){
                    t.right=new Node();
                }
                t=t.right;
            }
            else{
                if(t.left==null){
                    t.left=new Node();
                }
                t=t.left;
            }
        }
    }
    
    public static int getMaxXor(Node root, int num, int n){
        Node t=root;
        int res=0;
        
        for(int i=n;i>=0;i--){
            if((num & 1<<i)!=0){
                if(t.left==null){
                    res+=1<<i;
                    t=t.right;
                }
                else{
                    t=t.left;
                }
            }
            else{
                if(t.right==null){
                    t=t.left;
                }
                else{
                    res+=1<<i;
                    t=t.right;
                }
            }
        }
        return res;
    }
}

 

