//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        struct Node * a=NULL,*prev;
        
         while(node1!=NULL)
         {
             if(a==NULL)
             {
                 a=node1;
                 
                 node1=node1->next;
                 a->next=NULL;
             }
             else
             {   
                 prev=node1;
                 
                 node1=node1->next;
                 prev->next=a;
                 a=prev;
             }
         }
         struct Node *b=NULL,*previ;
          while(node2!=NULL)
         {
             if(b==NULL)
             {
                 b=node2;
                 
                 node2=node2->next;
                 b->next=NULL;
             }
             else
             {   
                 previ=node2;
                 
                 node2=node2->next;
                 previ->next=b;
                 b=previ;
             }
         }
         
         node1=a;
         node2=b;
         a=NULL,b=NULL,prev=NULL,previ=NULL;
         while(node1!=NULL&&node2!=NULL)
         {
             if(node1->data>node2->data)
             {   
                 if(a==NULL)
                { a=node1;
                  b=a;
                }
                 else 
                 {  
                     a->next=node1;
                     a=a->next;
                 
                 }
                 
                 node1=node1->next;
                 
             }
             else 
             {   
                 if(a==NULL)  
                 {
                     a=node2;
                     b=a;
                 }
                 else
                 {
                     a->next=node2;
                     a=a->next;
                 
                 }
                 
                 node2=node2->next;
                 
             }
         }
         if(node1!=NULL)
         {   
             if(a!=NULL)
             a->next=node1;
             else a=node1;
         }else 
         {   if(a!=NULL)
             a->next=node2;
             else a=node2;
         
         }
         if(b==NULL)b=a;
         return b;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends