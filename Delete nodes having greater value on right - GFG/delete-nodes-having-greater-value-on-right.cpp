//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
   
Node* compute(Node* head) {
    Node* dummy = new Node(-1);
    dummy->next = head;

    Node* current = dummy;
    while (current->next != nullptr && current->next->next != nullptr) {
        bool flag = false;
        Node* temp = current->next;

        while (temp->next != nullptr) {
            if (current->next->data < temp->next->data) {
                flag = true;
                break;
            }
            temp = temp->next;
        }

        if (flag) {
            Node* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
        } else {
            current = current->next;
        }
    }

    head = dummy->next;
    delete dummy;
    return head;
}
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends