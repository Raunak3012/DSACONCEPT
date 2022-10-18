#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        //contructor
        Node (int data){
            this->data = data;
            this->next = NULL;
        }

        //destructor
        ~ Node(){
            int value = this->data;

            if (this->next!=NULL){
                delete next;
                this->next = NULL;
            }

            cout<<"memory free for node with data "<<value<<endl;
        }
};

void InsertAtHead(Node* &head, int d){  //we pass head as refernce because we don't want to make a new copy of LL
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int d){  
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void InsertInMiddle(Node* &t, int d, int n){  
    Node* temp = new Node(d);
    int count=0;
    while(count<n/2 - 1){
        t = t->next;
        count++;
    }

    Node* curr = t->next;
    t->next = temp;
    t = temp;
    temp->next = curr;
}

//to free memory we need to write destructor
void deleteNode(int position, Node* &head,Node* &tail, int n){
    
    //delete 1st node
    if (position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    //delete last node (all this seperate code is just to take care that tail must point last node after deletion)
    if (position == n){
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt<position){
            cnt++;
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = NULL;
        tail = prev;
        
        delete curr;
    }

    //delete any other node
    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt<position){
            cnt++;
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}

int main(){

    //create a new node
    Node* node1 = new Node(3);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    Node* head = node1;
    Node* tail = node1;

    // InsertAtHead(head, 12);
    // InsertAtHead(head, 4);

    InsertAtTail(tail, 4);
    InsertAtTail(tail, 10);
    InsertAtTail(tail, 15);
    InsertAtTail(tail, 17);

    Node* t = head;
    InsertInMiddle(t, 8, 4);



    print(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    deleteNode(6, head, tail, 6);
    print(head);

    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
}