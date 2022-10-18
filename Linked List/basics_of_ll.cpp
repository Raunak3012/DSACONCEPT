#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
        int data;
        Node* next;

    //contructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        int val = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }

        cout<<"memory free for node with data "<<val<<endl;
    }
};

void InsertNode(Node* &tail, int element, int d){
    //assuming element is already present in ll

    //if empty LL
    if (tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;  //condition of circular LL
    }

    //non empty list
    else{

        Node* curr = tail;
        while(curr->data!=element){
            curr = curr->next;
        }

        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail, int value){
    //If LL is empty
    if (tail == NULL){
        cout<<"check again, as LL is empty "<<endl;
    }

    else{
        //assuming value is presenet in LL;

        Node* prev = tail;
        Node* curr = prev->next;

        if (curr == prev){   //this is used to hande if there is only one node
            tail = NULL;      //(so if we delete that single node then we lost tail which gives segmentation fault)  
        }

        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        if (tail == curr){
            tail = curr->next;
        }
        curr->next = NULL; 
        
        delete curr;
    }
}

void print(Node* tail){
    Node* temp = tail;

    cout<<tail->data<<" ";
    while(tail->next!=temp){
        tail = tail->next;
        cout<<tail->data<<" ";
    }

    cout<<endl;
}

int main(){
    Node* tail = NULL;

    InsertNode(tail, 5, 3);
    InsertNode(tail, 3, 7);
    // InsertNode(tail, 3, 9);
    // InsertNode(tail, 9, 6);
    // InsertNode(tail, 6, 5);
    print(tail);

    deleteNode(tail, 3);
    print(tail);

    // deleteNode(tail, 6);
    // print(tail);

    // deleteNode(tail, 7);
    // print(tail);
    // Node* node1 = new Node(10);
    // Node* head = node1;
    // Node* tail = node1;
    // print(tail);
}