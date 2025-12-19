#include<bits/stdc++.h>
using namespace std;

class BSTNode{
    public:
        int data;
        BSTNode* left;
        BSTNode* right;
    BSTNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void insertNode(BSTNode* &root, int val){
    BSTNode* NewNode = new BSTNode(val);
    if(root == nullptr){
        root = NewNode;
        return;
    }
    BSTNode* temp = root;
    BSTNode* parent = nullptr;
    while(temp != nullptr){
        parent = temp;
        if(val < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if(val < parent->data)
        parent->left = NewNode;
    else
        parent->right = NewNode;
}

void deleteNode(BSTNode* &root, int val){
    if(root == nullptr) return;
    if(val < root->data)
        deleteNode(root->left, val);
    else if(val > root->data)
        deleteNode(root->right, val);
    else{
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            root = nullptr;
        }
        else if(root->left == nullptr){
            BSTNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == nullptr){
            BSTNode* temp = root;
            root = root->left;
            delete temp;
        }
        else{
            BSTNode* NewParent = root;
            BSTNode* New = root->right;
            while(New->left != nullptr){
                NewParent = New;
                New = New->left;
            }
            root->data = New->data;
            if(NewParent != root)
                NewParent->left = New->right;
            else
                NewParent->right = New->right;
            delete New;
        }
    }

}

void inorder(BSTNode* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){ 
    BSTNode* root = nullptr;
    int val;
    char x = 'y';
    while(x!='n' && x!='N'){
        cout << "Enter value to insert: ";
        cin >> val;
        insertNode(root, val);
        cout << "Do you want to continue (y/n)? ";
        cin >> x;
    }

    char x = 'y';
    while(x!='n' && x!='N'){
        cout << "Enter value to delete: ";
        cin >> val;
        deleteNode(root, val);
        cout << "Do you want to continue (y/n)? ";
        cin >> x;
    }
        
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    return 0;
}