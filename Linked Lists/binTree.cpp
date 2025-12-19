#include<bits/stdc++.h>
using namespace std;

class binTree{
    public:
        int data;
        binTree* left;
        binTree* right;
    binTree(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void insertNode(binTree* &root, int val){
    binTree* newNode = new binTree(val);
    if(root == nullptr){
        root = newNode;
        return;
    }
    queue<binTree*> q;
    q.push(root);
    char x; 
    while(!q.empty()){
        binTree* temp = q.front();
        q.pop();
        if(temp->left == nullptr){
            temp->left = newNode;
            return;
        }
        else{
            q.push(temp->left);
        }
        if(temp->right == nullptr){
            temp->right = newNode;
            return;
        }
        else{
            q.push(temp->right);
        }
    }
}

void preorder(binTree* root){
    if(root == nullptr) return;
    stack<binTree*> st;
    st.push(root);
    while(!st.empty()){
        binTree* temp = st.top();
        st.pop();
        cout << temp->data << " ";
        if(temp->right != nullptr) st.push(temp->right);
        if(temp->left != nullptr) st.push(temp->left);
    }
}

int main() {
    binTree* root = nullptr;
    int val;
    char x = 'y'; 
    while(x!='n' && x!='N'){
        cout << "Insert? (Y/N)" << endl;
        cin >> x;
        if(x == 'y' || x == 'Y'){
            cout << "Enter value: " << endl;
            cin >> val; 
            insertNode(root, val);
        }
    }
    
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    
    return 0;
}
