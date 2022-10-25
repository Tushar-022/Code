//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.

Node* buildTre(int* in,int instart,int inend,int* post,int poststart,int postend,unordered_map<int,int>&m)
{
    if(poststart>postend|| instart>inend)
    return NULL;
    
    Node* root=new Node(post[postend]);
    int inRoot=m[post[postend]];
    int numsleft=inRoot-instart;
    root->left=buildTre(in,instart,inRoot-1,post,poststart,poststart+numsleft-1,m);
    root->right=buildTre(in,inRoot+1,inend,post,poststart+numsleft,postend-1,m);
    return root;
}
 
Node *buildTree(int in[], int post[], int n) {

    unordered_map<int,int>m;
    for(int i=0;i<n;i++)
    m[in[i]]=i;
   return  buildTre(in,0,n-1,post,0,n-1,m);
    
}
