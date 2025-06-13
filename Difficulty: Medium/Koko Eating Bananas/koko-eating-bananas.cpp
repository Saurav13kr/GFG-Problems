class Solution {
  public:
  int f(int mid,vector<int>&arr,int k){
      int cnt=0;
      for(int i=0;i<arr.size();i++){
          cnt+=((arr[i]+mid-1)/mid);
          if(cnt>k) return cnt;
      }
      
      return cnt;
  }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int st=1;
        int e=*max_element(arr.begin(),arr.end());
        int ans=-1;
        while(st<=e)
        {
            int mid=st+(e-st)/2;
            if(f(mid,arr,k)<=k){
                ans=mid;
                e=mid-1;
            }
                
            
            else st=mid+1;
        }
        
        return ans;
    }
};