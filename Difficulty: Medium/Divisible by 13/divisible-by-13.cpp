class Solution {
  public:
    bool divby13(string &s) {
        string curr=s;

        while(curr.size()>2){
            int last=curr.back()-'0';
            curr.pop_back();

            // compute mod 13 of the rest
            int rem=0;
            for(char c:curr){
                rem=(rem*10+(c-'0'))% 13;
            }

            rem=(rem+(last*4)%13)%13;
            curr=to_string(rem);
        }

        int num=stoi(curr);
        return num%13==0;
    }
};