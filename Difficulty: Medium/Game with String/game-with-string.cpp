class Solution {
  public:
    int minValue(string &s, int k) {
        int sum=0;
        unordered_map<char, int> ump;
        for(char c:s)
        {
            ump[c]++;
        }
        priority_queue<int> maxHeap;
        for(const auto &elm:ump){
            maxHeap.push(elm.second);
        }
        while(k-- && !maxHeap.empty()){
            int top=maxHeap.top();
            maxHeap.pop();
            if(top>0) top=top-1;
            maxHeap.push(top);
            
        }
        while(!maxHeap.empty()){
            sum+=maxHeap.top()*maxHeap.top();
            maxHeap.pop();
        }
        return sum;
    }
};