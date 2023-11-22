#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
class LIST{
public:
    node* head;

    LIST(){
            head = NULL;
    }
    void insertAtTheHead(int value);
    void insertAtTheEnd(int value);
    void insertAtTheMidAfterVal(int value);
    void insertAtTheMidAfterNode(node* prev_node);
    void insertAtTheMidBeforeNode(node* next_node);
    void insertAfterValue(int value, int afterValue);
    void printList(){
        node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ->";
            temp=temp->next;
        }
        cout<<endl;
        cout<<"Printing done.."<<endl;
    }
    void deleteAValue(int value){
        cout<<"Welcome to deletevalue: "<<value<<endl;
        node *nodeToDelete = head, *prev = NULL;

        if(nodeToDelete == NULL){
            cout<<"Empty List, can't delete"<<endl;
            return;
        }

        if(nodeToDelete->data == value){
            head = head->next;
            free(nodeToDelete);
            return;
        }

        while(nodeToDelete->data != value && nodeToDelete!=NULL){
            prev = nodeToDelete;
            nodeToDelete = nodeToDelete->next;
        }
        if(nodeToDelete==NULL){
            cout<<"Data not found in Linked List; Can't delete";
            return;
        }
        else{
            prev->next = nodeToDelete->next;
            free(nodeToDelete);

        }

    }

};

void LIST::insertAtTheHead(int value){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = head;
    head = new_node;

}
void LIST::insertAtTheEnd(int value){
    node *nn = new node;
    nn->data = value;
    nn->next = NULL;

    node* temp = head;
    if(head == NULL){
        head=nn;
    }
    else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = nn;
    }
}
void LIST::insertAfterValue(int value, int afterValue){
    node* nn = new node;
    nn->data = value;
    nn->next = NULL;

    node* temp = head;
    while(temp->data!=afterValue){

        temp = temp->next;
        if(temp==NULL){
            cout<<afterValue<<" not found in the list"<<endl;
        return;
        }
    }
    nn->next = temp->next;
    temp->next = nn;

}
int main(){
    cout<<"Welcome to the world of Singly Linked List.."<<endl;
    LIST mylist;
    mylist.insertAtTheHead(5);
    mylist.insertAtTheEnd(10);
    mylist.insertAtTheEnd(15);
    mylist.insertAtTheEnd(25);
    mylist.insertAtTheHead(1);

    mylist.printList();

    mylist.insertAfterValue(20,15);
    mylist.printList();

    mylist.insertAfterValue(2,100);
    mylist.printList();

    mylist.insertAfterValue(2,1);
    mylist.printList();

    mylist.deleteAValue(15);
    mylist.printList();

    mylist.deleteAValue(1);
    mylist.printList();
    return 0;
}
