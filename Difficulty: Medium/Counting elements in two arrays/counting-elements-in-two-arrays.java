class Solution {
    public static ArrayList<Integer> countLessEq(int a[], int b[]) {
        Arrays.sort(b);
        ArrayList<Integer> res=new ArrayList<>();
        
        for(int i=0;i<a.length;i++){
            int l=0, r=b.length-1;
            
            while(l<=r){
                int mid=l+(r-l)/2;
                if(b[mid]<=a[i]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            res.add(r+1);
        }
        
        return res;
    }
}