//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way


  //int get(int key_) {
// design the class in the most optimal way

class LRUCache
{
    public:
    struct node{
        public:
        int key,value;
        node* next;
        node* prev;
        node(int x,int y){
            next=NULL;
            prev=NULL;
            key=x;
            value=y;
        }
    };
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
        
    void addnode(int x,int y){
        node* insnode= new node(x,y);
        insnode->next=head->next;
        head->next->prev=insnode;
        head->next=insnode;
        insnode->prev=head;
    }
    
    void delnode(node* delnode)
    {
        delnode->prev->next=delnode->next;
        delnode->next->prev=delnode->prev;
        delete delnode;
    }
        
    
    int size;
    unordered_map <int,node*> mp;
    LRUCache(int cap)
    {
        size=cap;
        head->next=tail;
        tail->prev=head;
       
    }
    
    int GET(int key)
    {
        if (mp.find(key) != mp.end())
        {
            addnode(key,mp[key]->value);
            delnode(mp[key]);
            mp[key]=head->next;
            return head->next->value;
        }
        else{
        return -1;}
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        
        if(mp.size()==size)
        {
            if(mp.find(key) != mp.end())
            {
               //mp[key]->value=value;
               delnode(mp[key]);
               addnode(key,value);
               mp[key]=head->next;
            }
            else{
            mp.erase(tail->prev->key);
            delnode(tail->prev);
            addnode(key,value);
            mp.insert({key,head->next});
            }
        }
        else{
            if(mp.find(key) != mp.end())
            {
               mp[key]->value=value;
               delnode(mp[key]);
               addnode(key,value);
               mp[key]=head->next;
            }
            else{
            addnode(key,value);
            mp.insert({key,head->next});
            }
        }
    }
};   



//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends