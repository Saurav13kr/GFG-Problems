//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String arr[] = br.readLine().split(" ");
            int prices[] = new int[arr.length];

            for (int i = 0; i < arr.length; i++) {
                prices[i] = Integer.parseInt(arr[i]);
            }
            Solution obj = new Solution();
            int res = obj.maximumProfit(prices);
            System.out.println(res);
        }
    }
}
// } Driver Code Ends


// User function Template for Java


class Solution {
    public int maximumProfit(int prices[]) {
        int buy = prices[0];
       int profit=0;
       for(int i=1; i<prices.length; i++)
       {
            if(prices[i] < buy){
                buy = prices[i];
            } else if(prices[i]-buy > profit){
                profit=prices[i]-buy;
            }
       }

       return profit;
    }
}
