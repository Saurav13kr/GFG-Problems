//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    vector<Node*> children;
    Node(int val){
        data=val;
    }
};

class N_ary_Tree{
public:
    Node *root;
    int size;
    N_ary_Tree(){
        root=NULL;
        size=0;
    }
    Node *add(int new_key,Node *parent_key=NULL){
        Node *new_node = new Node(new_key);
        if(parent_key == NULL){
            root = new_node;
            size = 1;
        }
        else{
            parent_key->children.push_back(new_node);
            size += 1;
        }
        return new_node;
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> get(Node* root)
    {
        queue<Node*> q;
        vector<int> ans;
        ans.push_back(root->data);
        q.push(root);
        
        while(!q.empty())
        {
            Node* tt=q.front();
            q.pop();
            
            vector<Node*> child=tt->children;
        
            for(auto a: child)
            {
                q.push(a);
                ans.push_back(a->data);
            }
            
        }
        return ans;
    }

    void solve(Node* root,map<pair<int,vector<int>>,int> &mp)
    {
        if(root==NULL)return;
        
        vector<Node*> child=root->children;
        
        vector<int> res=get(root);
        mp[{root->data,res}]++;
        
        if(mp[{root->data,res}]>1)return;
        
        for(auto a: child)
        {
            
            solve(a,mp);
        }
        
        return;
    }

    int duplicateSubtreeNaryTree(Node *root){
        map<pair<int,vector<int>>,int> mp;
        solve(root,mp);
        int cnt=0;
        for(auto a: mp)
        {
            if(a.second>=2)cnt++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        if(i==0){
            string p;
            getline(cin,p);
        }
        string str;
        getline(cin,str);
        stringstream st(str);
        vector<string> s;
        string y;
        while(st>>y){
            s.push_back(y);
        }
        N_ary_Tree *tree = new N_ary_Tree();
        Node *curr;
        queue<Node*> q;
        for(int i=0;i<s.size();i++){
            if (i == 0){
                curr=tree->add(stoi(s[0]));
            }
            else if(s[i] == " "){
                continue;
            }
            else if(q.size() and s[i] == "N"){
                curr = q.front();
                q.pop();
            }
            else if(s[i] != "N"){
                q.push(tree->add(stoi(s[i]), curr));
            }
        }
        Solution ob;
        int res = ob.duplicateSubtreeNaryTree(tree->root);
        cout<<res<<endl;
    }
}
// } Driver Code Ends