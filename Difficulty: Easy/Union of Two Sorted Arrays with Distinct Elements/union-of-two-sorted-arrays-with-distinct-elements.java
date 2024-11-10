//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            // First array input
            String[] str1 = br.readLine().trim().split(
                " "); // Read the first line and split by spaces
            int n = str1.length;
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(str1[i]); // Convert each element to an integer
            }

            // Second array input
            String[] str2 = br.readLine().trim().split(
                " "); // Read the second line and split by spaces
            int m = str2.length;
            int[] b = new int[m];
            for (int i = 0; i < m; i++) {
                b[i] = Integer.parseInt(str2[i]); // Convert each element to an integer
            }

            Solution obj = new Solution();
            ArrayList<Integer> res = new ArrayList<Integer>();
            res = obj.findUnion(a, b);
            for (int i = 0; i < res.size(); i++) System.out.print(res.get(i) + " ");
            System.out.println();

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java

// a,b : the arrays

class Solution {
    // Function to return a list containing the union of the two arrays.
    public static ArrayList<Integer> findUnion(int a[], int b[]) {
        // add your code here
     ArrayList<Integer> li = new ArrayList<>();
     int point = 0;
     int point1 = 0;
     while (point < a.length && point1 < b.length) {
         if (a[point] == b[point1]) {
             li.add(a[point]);
             point++;
             point1++;
         } 
         else if (a[point] > b[point1]) {
             li.add(b[point1]);
             point1++;
         } 
         else {
             li.add(a[point]);
             point++;
         }
     }
     if (point < a.length) {
         for (int i = point; i < a.length; i++) 
         {
             li.add(a[i]);
             point++;
         }
     }
     if (point1<b.length) {
        for (int i = point1; i < b.length; i++) {
            li.add(b[i]);
            point1++;
        }
     }
     return li;
    }
}