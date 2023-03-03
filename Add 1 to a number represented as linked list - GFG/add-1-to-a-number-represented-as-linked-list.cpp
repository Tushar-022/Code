//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
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
    
    Node* addOne(Node *l1) 
    {
        Node* curr1=rev(l1);
        Node* curr2=new Node(1);
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
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends