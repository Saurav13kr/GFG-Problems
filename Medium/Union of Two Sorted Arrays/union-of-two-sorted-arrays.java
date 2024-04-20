//{ Driver Code Starts
//Initial Template for Java


import java.util.*;
import java.io.*;
import java.lang.*;

class Main
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t  =Integer.parseInt(read.readLine());
        
        while(t-- > 0)
        {
            String st[] = read.readLine().trim().split(" ");
            int N = Integer.parseInt(st[0]);
            int M = Integer.parseInt(st[1]);
            
            int arr1[] = new int[N];
            int arr2[] = new int[M];
            
            st = read.readLine().trim().split(" ");
            for(int i = 0; i < N; i++)
              arr1[i] = Integer.parseInt(st[i]);
            
            st = read.readLine().trim().split(" ");  
            for(int i = 0; i< M; i++)
              arr2[i] = Integer.parseInt(st[i]);
            
            Solution obj = new Solution();
            ArrayList<Integer> res = new ArrayList<Integer>();
            res = obj.findUnion(arr1, arr2, N, M);
            for(int i = 0;i<res.size();i++)
                System.out.print(res.get(i) + " ");
            System.out.println(); 
        }
    }
}



// } Driver Code Ends


//User function Template for Java

//arr1,arr2 : the arrays
// n, m: size of arrays
class Solution
{
   
    public static ArrayList<Integer> findUnion(int arr1[], int arr2[], int n, int m)
    {
      ArrayList<Integer> ans=new ArrayList<>();
      Union(arr1,arr2,n,m,ans);
      return ans;
    }
    static void Union(int arr1[], int arr2[], int n, int m, ArrayList<Integer> ans)
    {
        int arr[]=new int[n+m];
        for(int i=0;i<n;i++)
        {
            arr[i]=arr1[i];
        }
        for(int i=0;i<m;i++)
        {
            arr[n+i]=arr2[i];
        }
        Arrays.sort(arr);
        for(int i=1;i<n+m;i++)
        {
            if(arr[i-1]!=arr[i])
            {
                ans.add(arr[i-1]);
            }
        }
        ans.add(arr[n+m-1]);
    }
}



