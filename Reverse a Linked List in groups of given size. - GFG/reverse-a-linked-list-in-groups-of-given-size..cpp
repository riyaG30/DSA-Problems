//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    node* kreverse(struct node *head, int k)
    {
        if(head == NULL) return  NULL;
        // 1 case we will reverse, and the others will be handled by recyrsion
        // that is first group of k elements
        node * prev = NULL;
        node* curr = head;
        node * fwd ;
        int count = 0;
        while(curr != NULL && count < k)
        {
            fwd = curr->next;
            curr ->next = prev;
            prev = curr;
            curr = fwd;
            count++;
        }
        // check fwd is null or not
        if(fwd != NULL)
        head->next = kreverse(fwd,k);
        return  prev;
    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method 
        return kreverse(head,k);
         
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends