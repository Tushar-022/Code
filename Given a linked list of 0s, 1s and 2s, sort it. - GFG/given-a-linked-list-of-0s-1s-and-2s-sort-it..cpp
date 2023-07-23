//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    

   Node* getMid(Node* head)
    {
        Node* slow=head;
        Node* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    Node* merge(Node* l1,Node* l2)
    {
        if(l1==NULL)
        return l2;
        if(l2==NULL)
        return l1;
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->data>l2->data)
            {
                temp->next=l2;
                l2=l2->next;
                
            }
            else
            {
                temp->next=l1;
                l1=l1->next;
            }
            temp=temp->next;
        }
        if(l1!=NULL)
        {
            while(l1!=NULL)
            {
                temp->next=l1;
                temp=temp->next;
                l1=l1->next;
            }
        }

        if(l2!=NULL)
        {
            while(l2!=NULL)
            {
                temp->next=l2;
                temp=temp->next;
                l2=l2->next;
            }
        }
        return dummy->next;
    }


    
    Node* segregate(Node *head) {
        
          if(head==NULL || head->next==NULL)
        return head;
       
       Node* curr=head; 
       
        Node* mid=getMid(head);
        Node* temp=mid->next;
        mid->next=NULL;
       Node* left= segregate(curr);
        Node* right=segregate(temp);
        return merge(left,right);
        
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends