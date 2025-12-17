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

int insertBeginning(Node* &head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    return 0;
}   

int insertPos(Node*head, int val, int pos){
    Node* newNode = new Node(val);
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return 0;
    }
    Node* temp = head;
    for (int i = 0; i < pos-2 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) return 0;
    newNode->next = temp->next;
    temp->next = newNode;
    return 0;

}

int deleteBeginning(Node* &head){
    if(head == nullptr) {
        cout << "Empty" << endl;
        return 0;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return 0;
}

int deleteNode(Node* &head, int val){
    if (head == nullptr) {
        cout << "Empty" << endl;
        return 0;
    }

    Node* temp = head; 
    while(temp->next != nullptr){
        if(temp -> next->data == val){
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            return 0;
        }
        temp = temp->next;
    }
    return 0;
}

int deletePos(Node* &head, int pos){
    if(head == nullptr) {
        cout << "Empty" << endl;
        return 0;
    }
    if(pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return 0;
    }
    Node* temp = head;
    for(int i=0; i<pos-2 && temp != nullptr; i++){
        temp = temp->next;
    }
    if(temp == nullptr || temp->next == nullptr) return 0;
    Node* del = temp->next;
    temp->next = temp->next->next;
    delete del;
    return 0;
}

int sumElements(Node* head){
    int sum = 0;
    Node* temp = head;
    while(temp != nullptr){
        sum += temp->data;
        temp = temp->next;
    }
    return sum;

}

int mergeList(Node* &head1, Node* &head2){
    if(head1 == nullptr) {
        head1 = head2;
        return 0;
    }
    Node* temp = head1;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = head2;
    return 0;
}

int sortList(Node* &head){
    if(head == nullptr)
        return 0;
    Node* temp = head;
    
    for(Node* i = head; i != nullptr; i = i->next) {
        for(Node* j = head; j->next != nullptr; j = j->next) {
            if(j->data > j->next->data) {
                int temp_data = j->data;
                j->data = j->next->data;
                j->next->data = temp_data;
            }

        }

    }
    return 0;
}

int revList(Node* &head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return 0;
}

int countElements(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
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
    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);
    insertBeginning(head, 5);
    insertPos(head, 15, 3);
    display(head);
    deleteBeginning(head);
    display(head);
    deleteNode(head, 20);
    display(head);
    deletePos(head, 2);
    display(head);
    cout << "Sum: " << sumElements(head) << endl;
    Node* head2 = nullptr;
    insertNode(head2, 40);
    insertNode(head2, 50);
    mergeList(head, head2);
    display(head);
    sortList(head);
    display(head);
    revList(head);
    display(head);
    cout << "Count: " << countElements(head) << endl;
    return 0;
}

