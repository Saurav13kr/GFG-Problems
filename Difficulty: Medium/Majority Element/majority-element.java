//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class Geeks {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine()).trim().split(" ");
            int arr[] = new int[str.length];
            for (int i = 0; i < str.length; i++) arr[i] = Integer.parseInt(str[i]);
            System.out.println(new Solution().majorityElement(arr));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    static int majorityElement(int arr[]) {
        int me=arr[0];
        int cnt=1;
        int n=arr.length;
        for(int i=1;i<n;i++){
            if(arr[i]==me){
                cnt++;
            }else {
                if(cnt>1){
                    cnt--;
                }else {
                    me=arr[i];
                }
            }
        }
        
        cnt=0;
        for(int a: arr)if(me==a)cnt++;
        
        return cnt>n/2?me:-1;
        
    }

}