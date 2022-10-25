//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
        Node* buildTree(int pre[],int prestart,int preend,int in[],int instart,int inend,unordered_map<int,int>&m)
        {
            if(prestart>preend|| instart>inend)
            return NULL;
            Node* root=new Node(pre[prestart]);
            
            int inRoot=m[root->data];
            int numsleft=inRoot-instart;
            root->left=buildTree(pre,prestart+1,prestart+numsleft,in,instart,inRoot-1,m);
            root->right=buildTree(pre,prestart+numsleft+1,preend,in,inRoot+1,inend,m);
             return root;
        }
       
    Node* buildTree(int in[],int pre[], int n)
    {
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        m[in[i]]=i;
        Node* root= buildTree(pre,0,n-1,in,0,n-1,m);
        return root;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends