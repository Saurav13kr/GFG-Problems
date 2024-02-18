//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class Searching
{
    public static void main (String[] args)throws IOException {

        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0)
        {
           String a[] = read.readLine().trim().split("\\s+");
           int n = Integer.parseInt(a[0]);
           long x = Long.parseLong(a[(int)1]);
           String st[] = read.readLine().trim().split("\\s+");
        
           long arr[] = new long[n];
           for(int i = 0; i < n; i++)
           {
               arr[i] = Long.parseLong(st[i]);
           }
           
           out.println(new Solution().findFloor(arr, n, x));
          
        }
        out.close();
    }
    
}
// } Driver Code Ends


class Solution{
    
    // Function to find floor of x
    // arr: input array
    // n is the size of array
    static int findFloor(long arr[], int n, long x) {
        return find(arr, 0, n - 1, x, -1);
    }

    static int find(long arr[], int start, int end, long x, int ans) {
        if (start <= end) {
            // find mid
            int mid = start + (end - start) / 2;
            if (arr[mid] == x) 
                return mid;
            else if (arr[mid] < x) {
                ans = mid;
                return find(arr, mid+1, end, x, ans);
            } else {
                return find(arr, start, mid - 1, x, ans);
            }
        }
        return ans;
    }
    
}
