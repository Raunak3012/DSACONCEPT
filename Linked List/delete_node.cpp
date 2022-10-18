#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    //constructor
    Node(int d){
        this -> data = d;
        this -> next = nullptr;
    }
    
    //destructor
    ~Node(){
        int val = this -> data;
        if(this -> next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory free of Node: "<<val<<endl;
    }
};

void insertElement(Node* &tail, int element, int d){
    //empty list 
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //non empty list
        //assuming element is present in the node
        Node* curr = tail;
        
        while(curr -> data != element){
            curr = curr -> next;
        }
        //element found
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void deleteNode(Node* &tail, int value){
    //empty list
    cout<<"value to delete "<<value<<" "<<tail->data<<endl;
    if(tail == NULL){
        cout<<"list is empty"<<endl;
        return ;
    }

    else if(tail->data == value){
        Node* temp = tail;

        while(temp->next->data != value){
            temp = temp->next;
        }

        Node* prev = tail;
        tail = tail->next;
        temp->next = prev->next;
        temp = temp->next;
        prev->next = NULL;
        delete prev;
    }

    else{
        //value is present in list
        Node* prev = NULL;
        Node* curr = tail -> next;
        
        while(curr -> data != value){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;
        
        //only one node is present
        if(prev == curr){
            tail = NULL;
        }
        
        //>= 2 node is present
        if(tail == curr){
            tail = prev;
        }
        
        curr -> next = NULL;
        delete curr;
    }
}

void print(Node* tail){
    Node* temp = tail;
    
    if(tail == NULL){
        cout<<"List is empty"<<endl;
    }
    else{
        do{
            cout<<tail -> data<<" ";
            tail = tail -> next;
        }while(tail != temp);
        cout<<endl;
    }
}

int main()
{
    Node* tail = NULL;
    insertElement(tail, 5, 3);
    print(tail);
    
    insertElement(tail, 3, 5);
    print(tail);
    
    insertElement(tail, 5, 7);
    print(tail);
    
    insertElement(tail, 7, 9);
    print(tail);
    
    insertElement(tail, 5, 6);
    print(tail);
    
    insertElement(tail, 9, 10);
    print(tail);
    
    insertElement(tail, 3, 4);
    print(tail);
    
    cout<<" Print karwao bhai "<<tail->data<<endl;
    deleteNode(tail, 3);
    print(tail);
    //print(tail);
    
    return 0;
}