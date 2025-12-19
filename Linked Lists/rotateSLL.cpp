#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

int rotateList(Node* &head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0)
        return 0;
    k+=1;
    Node* temp = head;
    int len = 0;
    while (temp != nullptr) {
        len++;
        temp = temp->next;
    }
    
    k = k % len;
    if (k == 0)
        return 0;
    
    temp = head;
    for (int i = 0; i < len - k - 1 ; i++)
        temp = temp->next;
    
    Node* newHead = temp->next;
    temp->next = nullptr;
    
    Node* last = newHead;
    while (last->next != nullptr)
        last = last->next;
    
    last->next = head;
    head = newHead;
    
    return 0;
}

int insertNode(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return 0;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return 0;
}

int display(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}

int main(){
    int n, x ,k; 
    Node* head = nullptr; 
    cout << "Enter number of elements" << endl;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> x;
        insertNode(head, x);
    }
    cout << "Enter number of rotations to be made" << endl;
    cin >> k; 
    while(k--){
        rotateList(head, k);
    
    }
    display(head);
    return 0;

}