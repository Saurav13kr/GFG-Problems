//{ Driver Code Starts
import java.util.*;

class Maxsum_Among_All_Rotations_Array
{
	public  static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0)
		{
			int n = sc.nextInt();
			int arr[] = new int[n];
			for(int i=0;i<n;i++)
				arr[i] = sc.nextInt();
			
			System.out.println(new GfG().max_sum(arr,n));
			
		t--;
		}
	}
	
}

// } Driver Code Ends


class GfG
{
    int max_sum(int A[], int n)
    {
    int ans=Integer.MIN_VALUE;
    int temp=0;
    int sum=0;
    int sumInd=0;
 
    for(int i=0;i<A.length;i++)
    {
    sum+=A[i];
    sumInd+=i*A[i];
    }
 
    for(int i=0;i<A.length;i++)
    {
        temp=sumInd-(sum-A[i])+(A[i]*(n-1));
        ans=Math.max(temp,ans);
        sumInd=temp;
    }
    return ans;
    }
}


