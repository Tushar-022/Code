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
        
        Node* rev(Node* head)
        {
            Node* prev=NULL;
            Node* curr=head;
            Node* next=NULL;
            while(curr!=NULL)
            {
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            return prev;
        }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        Node* curr1=rev(l1);
        Node* curr2=rev(l2);
        
        Node* dummy = new Node(-1);
        Node* temp=dummy;
        int carry=0,sum=0;
        while(curr1!=NULL || curr2!=NULL || carry!=0)
        {
            sum=0;
            if(curr1!=NULL)
            {
                sum+=curr1->data;
                curr1=curr1->next;
            }
            if(curr2!=NULL)
            {
                sum+=curr2->data;
                curr2=curr2->next;
            }
            sum+=carry;
            carry=sum/10;
            Node* add=new Node(sum%10);
            temp->next=add;
            temp=temp->next;
        }
        return rev(dummy->next);
        
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