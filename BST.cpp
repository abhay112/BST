#include<bits/stdc++.h>
using namespace std;

template<typename T>
class node{
    public:
        node *left;
        node *right;
        int data;
        node(int data){
            this -> data = data;
            left = right = NULL;
        }
};
node<int>* insertInBST(node<int>* root,int data){
     if(root == NULL){
         return new node<int>(data);
     }
     if(data <= root->data){
         root -> left = insertInBST(root->left,data);

     }
     else{
         root -> right = insertInBST(root->right,data);
     }
     return root;

}
node<int>* buildTress(){
    int d;
    cin >> d;
    node<int>* root = NULL;
    while(d!=-1){
        root = insertInBST(root,d);
        cin >> d;
    }
    return root;
}

// BST Level Wise

void bfs(node<int>*root){
    queue<node<int>*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node<int>* f = q.front();
        if(f == NULL){
            cout << endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << f->data <<" ";
            q.pop();
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return ;
} 


//Inorder print
void inorder(node<int>*root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << ",";
    inorder(root->right);
}

// BST Search
bool search(node<int>*root, int data){
    if(!root)
        return false;
    if(root->data == data){
        return true;
    }
    if(data <= root->data){
        return search(root->left,data);
    }else{
        return search (root->right,data);
    }
    // Or
    // return search(root->left,data) || search(root->right,data);


}
// Deletion 
node<int> * deleteNode(node<int> * root,int d){
    if(root== NULL)
        return NULL;
    else if(root -> data > d){
        root -> left = deleteNode(root->left,d);
        return root;
    }else if(root->data < d){
        root -> right = deleteNode(root->right,d);
        return root;
    }else{
        // 3 condition 
        // if node is leaf node
        // if nod has one child
        // if node has two child
        if(root->left==NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child
        if(root->left!=NULL && root ->right == NULL){
            node <int>*temp = root -> left;
            delete root;
            return temp;
        }

        if(root -> left == NULL && root -> right != NULL){
            node<int>* temp = root -> right;
            delete root;
            return temp;
        }
        // two child
        node<int>* minNode = root -> right;
        while(minNode -> left !=NULL){
            minNode = minNode -> left;
        }
        root -> data = minNode -> data;
        root -> right = deleteNode(root -> right,minNode->data);
        return root;
        

    }
}
 
// check tree is BST or NOT
bool isBST(node<int>* root,int mn = INT_MIN,int mx = INT_MAX){
    if(root == NULL)
        return true;
    if(root->data>=mn && root->data <= mx &&
        isBST(root->left,mn,root->data) && isBST(root->right,root->data,mx)){
            return true;
        }
        return false;
}
// another similar method 


  
bool recursive(node<int>* root, long lower, long upper) {
    if (root == NULL) return true;
        
    if (lower < root->data && root->data < upper) {
        return recursive(root->left, lower, root->data) && recursive(root->right, root->data, upper);
    }
        
    return false;
}
bool isValidBST(node<int>* root) {
    return recursive(root, LONG_MIN, LONG_MAX);
}
  

int main(){
    node<int>*root =buildTress();
    bfs(root);
    cout << endl;
    inorder(root);
    cout << endl;
    
    cout <<"binary tree is a BST " <<isBST(root);
    cout << isValidBST(root) ;
    cout << endl;
    cout << search(root,71);
    deleteNode(root,6);
    cout << endl;
    inorder(root);
    deleteNode(root,3);
    cout << endl;
    inorder(root);
    cout << endl;
    cout << isBST(root,0,0);



     
}


