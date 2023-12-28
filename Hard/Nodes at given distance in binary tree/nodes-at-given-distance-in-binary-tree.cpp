//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
    Node* createmapping(Node* root,unordered_map<Node*,Node*> &cm,int target)
    {
        queue<Node*> q;
        q.push(root);
        cm[root] = NULL;
        Node* ans = NULL;

       // using level order traversal
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            // finding the target node
            if(temp->data == target)
            {
                ans = temp;
            }
            if(temp->left)
            {
                // Mapping with parent node
                cm[temp->left] = temp;
                q.push(temp->left);
            }
            
            if(temp->right)
            {
                // mapping with parent node
                cm[temp->right] = temp;
                q.push(temp->right);
            }
        }
        // returning the target node
        return ans;
    }
    void check(Node* startNode,unordered_map<Node*,bool> &visited,vector<int> &ans,
    int k,unordered_map<Node*,Node*> &cm)
    {
        // base case
        if(k==0 || startNode == NULL)
        {
            if(startNode)
            {
                ans.push_back(startNode->data);
            }
            return;
        }
        // Marking the node visited 
        visited[startNode] = true;
        
        // left
        if(visited[startNode->left] != true && startNode->left !=NULL)
        {
            check(startNode->left,visited,ans,k-1,cm);
        }
        // right
        if(visited[startNode->right] != true && startNode->right != NULL)
        {
            check(startNode->right,visited,ans,k-1,cm);
        }
        // up(parent)
        if(visited[cm[startNode]] != true && cm[startNode] !=NULL)
        {
            check(cm[startNode],visited,ans,k-1,cm);
        }
    }
public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        
        vector<int> ans;
        
        // step 1 create a mapping of parent node's and find the target Node
        unordered_map<Node*,Node*> cm;
        Node* st = createmapping(root,cm,target);
        
        unordered_map<Node*,bool> visited;
        // step 2 check the right,left and parent node for k value
        check(st,visited,ans,k,cm);
        // step 3 sort the result 
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends