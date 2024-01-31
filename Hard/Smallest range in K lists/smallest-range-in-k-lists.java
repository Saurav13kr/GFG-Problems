//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

public class DriverClass
{
	public static void main(String args[]) 
	{
	   Scanner sc = new Scanner(System.in);
	   int t = sc.nextInt();
	   int range[];
	   while(t-- >0)
	   {
	     int n = sc.nextInt();
	     int k = sc.nextInt();
	     int arr[][] = new int[k][n];
	       for(int i = 0; i < k; i++)
	       {
	        for(int j = 0; j < n; j++)
	               arr[i][j] = sc.nextInt();
	       }
	       range = new Solution().findSmallestRange(arr, n, k);
	       System.out.println(range[0] + " " + range[1]);
	   }
	}
}

// } Driver Code Ends


class Node {
    int data;
    int row;
    int col;

    Node(int data, int i, int j) {
        this.data = data;
        row = i;
        col = j;
    }
}

class Solution {
    static int[] findSmallestRange(int[][] KSortedArray, int n, int k) {
        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.data));
        int maxi = Integer.MIN_VALUE;
        int mini = Integer.MAX_VALUE;
        for (int i = 0; i < k; i++) {
            Node temp = new Node(KSortedArray[i][0], i, 0);
            mini = Math.min(mini, temp.data);
            maxi = Math.max(maxi, temp.data);
            pq.add(temp);
        }
        int start = mini, end = maxi;
        while (!pq.isEmpty()) {
            Node temp = pq.poll();
            mini = temp.data;
            int row = temp.row;
            int col = temp.col;
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }
            if (col + 1 < n) {
                Node next = new Node(KSortedArray[row][col + 1], row, col + 1);
                maxi = Math.max(maxi, KSortedArray[row][col + 1]);
                pq.add(next);
            } else {
                break;
            }
        }
        return new int[]{start, end};
    }
}
