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
            int a[] = new int[arr.length];

            for (int i = 0; i < arr.length; i++) {
                a[i] = Integer.parseInt(arr[i]);
            }
            Solution obj = new Solution();
            int f = 0;
            String A = obj.minSum(a);
            System.out.println(A);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    String minSum(int[] arr) {
        Arrays.sort(arr);
        List<Integer> l1 = new ArrayList<Integer>();
        List<Integer> l2 = new ArrayList<>();

        for(int i=0; i<arr.length; i+=2){
            l1.add(arr[i]);
            if(i+1 < arr.length){
                l2.add(arr[i+1]);
            }
        }
        Collections.reverse(l1);
        Collections.reverse(l2);
        int i =0;
        int j = 0;
        int c= 0;
        int d =0;
        List<Integer> result = new ArrayList<>();
        while(i<l1.size() && j<l2.size()){
            int sum = l1.get(i++) + l2.get(j++) + c;
            c = sum /10;
            d = sum % 10;
            result.add(d);
        }
        while(i<l1.size())
        {
            int sum = l1.get(i++) + c;
            c = sum / 10;
            d = sum % 10;
            result.add(d);
        }
        while(j<l2.size())
        {
            int sum = l2.get(j++) + c;
            c = sum / 10;
            d = sum % 10;
            result.add(d);
        }
        while(c>0){
            d = c;
            c = d/10;
            d = d%10;
            result.add(d);
        }
        Collections.reverse(result);
        StringBuilder sb = new StringBuilder();
         i =0;
        while(i<result.size() && result.get(i) == 0){
            i++;
        }
        if(i == result.size()) return "0";
        for(int k = i; k<result.size(); k++){
            sb.append(result.get(k));
        }
        return sb.toString();
        

    }
}