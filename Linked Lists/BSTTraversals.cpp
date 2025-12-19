#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int data) {
    Node* t = new Node(data);
    if (root == nullptr) {
        return t;
    }
    Node* p = nullptr;
    Node* q = root;
    while (q != nullptr) {
        p = q;
        if (data < q->data) {
            q = q->left;
        } else if (data > q->data) {
            q = q->right;
        } else {
            return root;
        }
    }
    if (data < p->data) {
        p->left = t;
    } else {
        p->right = t;
    }
    return root;
}

Node* insert_rec(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert_rec(root->left, data);
    } else if (data > root->data) {
        root->right = insert_rec(root->right, data);
    }
    return root;
}

Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

Node* search_iter(Node* root, int key) {
    Node* q = root;
    while (q != nullptr) {
        if (q->data == key) {
            return q;
        } else if (key < q->data) {
            q = q->left;
        } else {
            q = q->right;
        }
    }
    return nullptr;
}

Node* inorder_succ(Node* root) {
    Node* q = root;
    while (q->left != nullptr) {
        q = q->left;
    }
    return q;
}

Node* delete_node(Node* root, int data) {
    if (root == nullptr) {
        return root;
    }
    if (data < root->data) {
        root->left = delete_node(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = inorder_succ(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

vector<vector<int>> level_order(Node* root) {
    vector<vector<int>> r;
    if (root == nullptr) return r;
    queue<Node*> s;
    s.push(root);
    while (!s.empty()) {
        int x = s.size();
        vector<int> l;
        for (int i = 0; i < x; i++) {
            Node* q = s.front();
            s.pop();
            l.push_back(q->data);
            if (q->left != nullptr) {
                s.push(q->left);
            }
            if (q->right != nullptr) {
                s.push(q->right);
            }
        }
        r.push_back(l);
    }
    return r;
}

int main() {
    Node* root = nullptr;
    vector<int> data_to_insert = {50, 30, 20, 40, 70, 60, 80};
    for (int data : data_to_insert) {
        root = insert(root, data);
    }

    cout << "INORDER TRAVERSAL:" << endl;
    inorder(root);
    cout << endl;

    int k = 40;
    Node* result = search_iter(root, k);
    if (result != nullptr) {
        cout << "Element " << k << " found in the BST." << endl;
    } else {
        cout << "Element " << k << " not found in the BST." << endl;
    }

    root = delete_node(root, 70);
    cout << "INORDER TRAVERSAL AFTER DELETION:" << endl;
    inorder(root);
    cout << endl;

    root = delete_node(root, 20);
    cout << "INORDER TRAVERSAL AFTER DELETION:" << endl;
    inorder(root);
    cout << endl;

    return 0;
}