//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int[] a = new int[s.length];
            for (int i = 0; i < s.length; i++) a[i] = Integer.parseInt(s[i]);

            Solution obj = new Solution();
            int res = obj.pairWithMaxSum(a);
            System.out.println(res);
        }
    }
}

// } Driver Code Ends

class Solution {
    public int pairWithMaxSum(int[] arr) {
        int len=arr.length;
        if(len==1) return -1;
        int max1=0,max2=0,sum=0;
        
        for(int i=0;i<len-1;i++)
        {
            max1=arr[i];
            max2=arr[i+1];
            sum=Math.max(sum,max1+max2);
        }
        return sum;
    }
}
