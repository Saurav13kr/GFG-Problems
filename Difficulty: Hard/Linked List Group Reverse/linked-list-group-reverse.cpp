//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        if (k <= 1 || head == NULL) {
            return head;
        }

        Node* current = head;
        Node* prev = NULL;

		int length = getLength(head);
		int count = length / k;
		if(length%k!=0) count++;
        while (count > 0) {
            Node* last = prev;
            Node* newEnd = current;

            Node* next = current->next;
            for (int i = 0; current != NULL && i < k; i++) {
                current->next = prev;
                prev = current;
                current = next;
                if (next != NULL) {
                    next = next->next;
                }
            }

            if (last != NULL)
            {
                last->next = prev;
            } 
            else {
                head = prev;
            }

            newEnd->next = current;

            prev = newEnd;
			count--;
        }
        return head;
    }
    int getLength(Node* head) {
		Node* node = head;
		int length = 0;
		while (node != NULL) {
			length++;
			node = node->next;
		}
		return length;
	}
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends