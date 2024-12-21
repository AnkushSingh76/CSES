#include<bits/stdc++.h>
using namespace std;
//Heap
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }
    void _insert(int node){
        size=size+1;
        arr[size]=node;
        int idx=size;
        while(idx>1){
            int parent=idx/2;
            if(arr[parent]<arr[idx]){
                swap(arr[parent],arr[idx]);
                idx=parent;
            }
            else{
                return;
            }
        }
    }
    void _delete(int node){
        swap(arr[1],arr[size]);
        size=size-1;
        int idx=1;
        while(idx<size){
            int left_idx=2*idx;
            int right_idx=2*idx+1;
            if(arr[left_idx]>arr[right_idx]){
                swap(arr[left_idx],arr[idx]);
                idx=left_idx;
            }
            else{
                swap(arr[right_idx],arr[idx]);
                idx=right_idx;
            }
        }
    }
    void _print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

//Tree Node
class TreeNode{
    public:
    int data;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int data){
        this->data;
        left=NULL;
        right=NULL;
    }
};
TreeNode* solve(TreeNode*root,int key){
    if(root==NULL){
        return root;
    }
    if(root->data==key){
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        if(root->left!=NULL&&root->right==NULL){
            TreeNode*temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL&&root->right!=NULL){
            TreeNode*temp=root->right;
            delete root;
            return temp;
        }
        else{
            TreeNode*temp=root->right;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            int val=temp->data;
            root->data=val;
            root->right=solve(root->right,val);
            return root;
        }
    }
    else if(root->data<key){
        return solve(root->right,key);
    }
    else{
        return solve(root->left,key);
    }
}
TreeNode*solve1(TreeNode*root,int key){
    if(root==NULL){
        TreeNode*node=new TreeNode(key);
        return node;
    }
    if(root->data>key){
        root->left=solve1(root->left,key);
    }
    else if(root->data<key){
        root->right=solve1(root->right,key);
    }
}

//Linked_List
class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
//Stack
class stack{
    int *arr;
    int top;
    int size;
    stack(int size){
        arr=new int[size];
        this->size=size;
        top=-1;
    }
    void push(int key){
        if(size-top>1){
            top++;
            arr[top]=key;
        }
        else{
            cout<<"Stack Overflow";
        }
    }
    int pop(){
        if(top>=0){
            int temp=arr[top];
            top--;
            return temp;
        }
        else{
            cout<<"Stack is Empty";
        }
    }
};
class stack_ll{
    public:
    Node*top;
    stack_ll(){
        top=NULL;
    }
    void push(int key){
        Node*temp=new Node(key);
        temp->next=top;
        top=temp;
    }
    int pop(){
        if(top!=NULL){
            Node*temp=top;
            int val=temp->data;
            top=top->next;
            delete temp;
            return val;
        }
        else{
            cout<<"Stack is Empty";
        }
    }
};

//Queue
class queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;
    queue(int size){
        arr=new int[size];
        this->size=size;
        front=0;
        rear=0;
    }
    void push(int key){
        if(rear==size){
            cout<<"Queue Overflow";
        }
        else{
            arr[rear]=key;
            rear++;
        }
    }
    int pop(){
        if(front==rear){
            cout<<"Queue is Empty";
        }
        else{
            for(int i=0;i<rear;i++){
                arr[i]=arr[i+1];
            }
            rear--;
        }
    }
};

//Two stack in an array
class stack_2{
    public:
    int *arr;
    int size;
    int top1;
    int top2;
    stack_2(int size){
        arr=new int[size];
        this->size=size;
        top1=-1;
        top2=size;
    }
    void push_1(int key){
        if(top2>top1+1){
            top1++;
            arr[top1]=key;
        }
        else{
            cout<<"Stack1 Overflow";
        }
    }
    void push_2(int key){
        if(top1<top2-1){
            top2--;
            arr[top2]=key;
        }
        else{
            cout<<"Stack2 Overflow";
        }
    }
    int pop_1(){
        if(top1>=0){
            int temp=arr[top1];
            top1--;
            return temp;
        }
        else{
            cout<<"Stack1 is Empty";
        }
    }
    int pop_2(){
        if(top2<size){
            int temp=arr[top2];
            top2++;
            return temp;
        }
        else{
            cout<<"Stack2 is empty";
        }
    }
};

//LRU Cache
class lru_cache{
    public:
    class node{
        public:
        int key;
        int val;
        node*prev;
        node*next;
        node(int key,int val){
            this->key=key;
            this->val=val;
        }
    };
    node*head=new node(-1,-1);
    node*tail=new node(-1,-1);
    int capacity;
    unordered_map<int,node*>mp;
    lru_cache(int capacity){
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(node*newnode){
        node*temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    void deletenode(node*delnode){
        node*temp1=delnode->prev;
        node*temp2=delnode->next;
        temp1->next=temp2;
        temp2->prev=temp1;
    }
    int get(int key){
        if(mp.find(key)!=mp.end()){
            node*temp=mp[key];
            int res=temp->val;
            mp.erase(key);
            deletenode(temp);
            addnode(temp);
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    void put(int key,int val){
        if(mp.find(key)!=mp.end()){
            node*temp=mp[key];
            mp.erase(key);
            deletenode(temp);
        }
        if(mp.size()==capacity){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,val));
        mp[key]=head->next;
    }
};
int main(){
    
}