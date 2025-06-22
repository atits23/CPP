#include<bits/stdc++.h>
using namespace std;
struct treenode{
    int val;
    treenode* left;
    treenode* right;
    treenode(int val,treenode*left,treenode *right){
        val=val;
        left=left;
        right=right;
    }
    treenode(int val){
        val=val;
        left=NULL;
        right=NULL;
    }
};
// Iterative preorder traversal
vector<int> preorder(treenode *root){
    vector<int>pre;
    if(root==NULL){
        return pre;
    }
    stack<treenode*>s;
    s.push(root);
    while(!s.empty()){
        root=s.top();
        s.pop();
       pre.push_back(root->val);
       if(root->right!=NULL){
        s.push(root->right);
       }
       if(root->left!=NULL){
        s.push(root->left);
       } 
    }
    return pre;
}
//Iterative Inorder traversal
vector<int> inorder(treenode* root){
    vector<int> in;
    treenode* node=root;
    if(node==NULL){
        return in;
    }
    stack<treenode*>st;
    while(true){
        if(node->left!=NULL){
            st.push(root->left);
            node=node->left;
        }
        else{
            if(st.empty()){
                break;
            }
            node=st.top();
            st.pop();
            in.push_back(node->val);
            node=node->right;
        }
    }
    return in;
}   

//all traversal in one go
vector<int> pre_in_post_traversal(treenode* root){
    vector<int> pre,in,post;
    stack<pair<treenode*,int>>st;
    st.push({root,1});
    if(root==NULL){
        return;
    }
    while(!st.empty()){
        auto it=st.top();
        st.pop();
        if(it.second==1){
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL){
                st.push({it.first->left,1});
            }
        }
        if(it.second==2){
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL){
                st.push({it.first->right,1});
            }
        }
        else{
            post.push_back(it.first->val);
        }
    }

}
int main(){
    int i=0;
    cout<<"Hello";
    return 0;
}
