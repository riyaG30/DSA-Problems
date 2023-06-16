//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverseList(struct Node* list)
{
    Node *prev = NULL, *cur = list, *next = NULL;
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverseList(first);
    second = reverseList(second);
 
    int carry = 0;
    Node *head = NULL, *prev = NULL;
    Node* sum = NULL;
    // if any one of these is left we are still left with addition
    while (first != NULL or second != NULL or carry == 1)
    {
        int newVal = carry;
        if (first)
            newVal += first->data;
        if (second)
            newVal += second->data;
        // to be used in the next node calculation
        carry = newVal / 10;
        newVal = newVal % 10;
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = newVal;
        // appending in the beginning of the final ans list,
        // this way we do not have to reverse in the end
        newNode->next = sum;
        sum = newNode;
        // initialising nodes for next iteration
 
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
 
    return sum;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends