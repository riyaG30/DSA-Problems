//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


// } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* rev(Node* head, int m, int n)
{
    if (head == NULL)
        return NULL;

    int cnt = 1;
    Node* pre = NULL;
    Node* curr = head;

    // Move the pointer to the m-th node
    while (curr != NULL && cnt < m) {
        pre = curr;
        curr = curr->next;
        cnt++;
    }

    Node* start = pre; // Node before the reversed section
    Node* revStart = curr; // Start of the reversed section

    // Reverse the portion from m to n
    while (curr != NULL && cnt <= n) {
        Node* next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
        cnt++;
    }

    // Connect the reversed portion to the remaining part
    if (start != NULL)
        start->next = pre;
    else
        head = pre; // If m = 1, update the head to the new start

    revStart->next = curr; // Connect the end of reversed portion to the remaining part

    return head;
}

Node* reverseBetween(Node* head, int m, int n)
{
    // Code here
    return rev(head, m, n);
}

};

//{ Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}

// } Driver Code Ends