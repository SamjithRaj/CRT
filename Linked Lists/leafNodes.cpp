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

vector<int> getLeafNodes(BSTNode* root) {
    vector<int> leafNodes;
    if (root == nullptr) {
        return leafNodes;
    }
    if (root->left == nullptr && root->right == nullptr) {
        leafNodes.push_back(root->data);
        return leafNodes;
    }
    vector<int> leftLeaves = getLeafNodes(root->left);
    leafNodes.insert(leafNodes.end(), leftLeaves.begin(), leftLeaves.end());
    vector<int> rightLeaves = getLeafNodes(root->right);
    leafNodes.insert(leafNodes.end(), rightLeaves.begin(), rightLeaves.end());
    return leafNodes;
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
    cout << "Leaf Nodes: ";
    vector<int> leafNodes = getLeafNodes(root);
    for(int i = 0; i < leafNodes.size(); ++i){
        if(i) 
        cout << ", ";
        cout << leafNodes[i];
    }
    cout << endl;
    return 0;
}
