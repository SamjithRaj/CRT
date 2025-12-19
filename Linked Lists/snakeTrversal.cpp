#include<bits/stdc++.h>
using namespace std;

class BSTNode {
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


int insertNode(BSTNode* &root, int val){
    BSTNode* NewNode = new BSTNode(val);
    if(root == nullptr){
        root = NewNode;
        return 0;
    }

    queue<BSTNode*> q;
    q.push(root);
    while(!q.empty()){
        BSTNode* temp = q.front(); q.pop();
        if(temp->left == nullptr){
            temp->left = NewNode;
            return 0;
        } else {
            q.push(temp->left);
        }
        if(temp->right == nullptr){
            temp->right = NewNode;
            return 0;
        } else {
            q.push(temp->right);
        }
    }
    return 0;
}   

vector<int> levelOrderReverse(BSTNode* root){
    vector<int> result;
    if(root == nullptr) return result;
    queue<BSTNode*> q;
    q.push(root);
    while(!q.empty()){
        int levelSize = q.size();
        vector<int> level;
        for(int i = 0; i < levelSize; ++i){
            BSTNode* temp = q.front(); q.pop();
            level.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        reverse(level.begin(), level.end()); 
        static bool leftToRight = true;
        if(leftToRight){
            result.insert(result.end(), level.rbegin(), level.rend());
        } else {
            result.insert(result.end(), level.begin(), level.end());
        }
        leftToRight = !leftToRight;
    }
    return result;
}

int main(){
    BSTNode* root = nullptr;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 6);
    insertNode(root, 7);
    insertNode(root, 8);
    cout << "Level Order Reverse Traversal: ";
    vector<int> res = levelOrderReverse(root);
    for(size_t i = 0; i < res.size(); ++i){
        if(i) cout << ",";
        cout << res[i];
    }
    cout << endl;
    return 0;
}
