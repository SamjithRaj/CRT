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


int isPrime(int num){
    if(num <= 1) return 0;
    for(int i=2; i<=sqrt(num); i++){
        if(num % i == 0)
            return 0;
    }
    return 1;
}

int insertBeginning(Node* &head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
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
    Node* head = nullptr; 
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> val;
        if(isPrime(val)){
            insertBeginning(head, val);
     }
        else{
            insertNode(head, val);
        }
}
cout << "Linked List: ";
    display(head);
    return 0;
}

