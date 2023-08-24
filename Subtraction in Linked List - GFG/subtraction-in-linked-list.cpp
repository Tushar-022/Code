//{ Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

Node* subLinkedList(Node* l1, Node* l2);

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
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends


/* Structure of linked list Node

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

//You are required to complete this method


/* Structure of linked list Node

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

//You are required to complete this method

 Node* reverse(Node* head)
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
    
    int getLength(Node* l1)
    {
        int len=0;
        while(l1!=NULL)
        {
            l1=l1->next;
            len++;
        }
        return len;
    }
    Node* subtract(Node* l1,Node* l2){
        Node* n1=reverse(l1);
        Node* n2=reverse(l2);
        
        int borrow=0;
        
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        
        while(n1!=NULL || n2!=NULL || borrow!=0)
        {
            int diff=0;
            
        if(n1!=NULL)
        {
            diff+=n1->data;
            n1=n1->next;
        }
    
        if(n2!=NULL)
        { 
          diff-=n2->data;
            n2=n2->next;
         }
            
        diff=diff+borrow;
        if(diff<0)
        {
            diff+=10;
            borrow=-1;
        }
        else
        {
            borrow=0;
        }
        if( diff!=0 ||n1 || n2)
       { 
           
       temp->next=new Node(diff);
       temp=temp->next;
        
       }
        }
        
        return reverse(dummy->next);
    }
    Node* solve(Node* l1,Node* l2)
    {
        while(l1!=NULL && l2!=NULL && l1->data==l2->data)
        {
            l1=l1->next;
            l2=l2->next;
        }
        if(l1==NULL && l2==NULL){
            return new Node(0);
        }
        else if(l1->data > l2->data){
            return subtract(l1,l2);
        }
        else{
            return subtract(l2,l1);
        }
    }

    Node* subLinkedList(Node* l1, Node* l2)
    {
        while(l1!=NULL && l1->data==0)
        l1=l1->next;
        while(l2!=NULL && l2->data==0)
        l2=l2->next;
        int t=getLength(l1);
        int p=getLength(l2);
        if(l1==NULL){
            return l2;
        }
        else if(l2==NULL){
            return l1;
        }
        //cout<<t<<"  "<<p<<endl;
        if(t==p)
        {
            Node* ans = solve(l1,l2);
            return ans;
        }
        else if(p>=t)
        {
            return subtract(l2,l1);
        }
        else{
            return subtract(l1,l2);
        }
        //return NULL;
    }
    