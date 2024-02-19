//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            String s = in.readLine();
            int k = Integer.parseInt(in.readLine());
            
            Solution ob = new Solution();
            System.out.println(ob.minValue(s, k));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution{
    static int minValue(String s, int k){
        
        int[] freq = new int[26];
        
        for(char ch : s.toCharArray())
          freq[ch-'a']++;
          
          for(int i = 0;i<k;i++) {
              Arrays.sort(freq);
              freq[25]-=1;
          }
          
          int sum = 0;
          
          for(int i = 25;i>=0;i--) {
              sum+=(freq[i]*freq[i]);
          }
          
          return sum;
    }
}