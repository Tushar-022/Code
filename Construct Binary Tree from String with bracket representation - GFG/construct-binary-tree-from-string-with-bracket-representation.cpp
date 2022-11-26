//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


// class Solution{
// public:
//     // function to construct tree from string
//     Node *treeFromString(string str){
//         // code here
//     }

//};
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
    int i=0;
public:
    // function to construct tree from string
    Node *treeFromString(string s){
        if(i>=s.length()) return NULL;
        string temp="";
        while(s[i]>='0' && s[i]<='9')
        {
            temp+=s[i];
            i++;
        }
        Node* ans=new Node(stoi(temp));
        if(s[i]=='(')
        {
            i++;
            ans->left=treeFromString(s);
        }
        if(s[i]=='(')
        {
            i++;
            ans->right=treeFromString(s);
        }
        i++;
        return ans;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends