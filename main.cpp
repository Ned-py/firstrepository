#include <iostream>
#include <string>
using namespace std;

class Node{
public:
int data;
Node *next;
};

class linkedlist {
public:
    Node *head;

    linkedlist(){
        head = NULL ;
    }

    bool IsEmpty() { // function checks if head is empty
        if (head == NULL) {
            return true;
        } else {
            return false;
        }
    }


    void InsertNode(int newvalue ){
        Node *NewNode = new Node(); // ???????
        NewNode->data = newvalue;

            if(IsEmpty()) { // if head is empty, we create a new node and set it to head
                NewNode->next = NULL;
                head = NewNode;
            }
            else{ // else head is not empty we add a new node and make it the head
                NewNode->next = head;
                head = NewNode;

            }
    }


    void display() {
        Node *Temp = head;
        while (Temp != NULL) {
            cout << Temp->data << endl;
            Temp = Temp->next;
        }
    }
    bool IsFound(int item){
        bool flag = false;
        Node *Temp = head;
        while (Temp != NULL) {
            if(Temp->data == item) {
                flag = true;
                Temp = Temp->next;
            }
            return flag;
        }
    }

    void insetbefore(int item, int newvalue){
        if(IsFound(item)) {
            Node *NewNode = new Node();
            NewNode->data = newvalue;
            Node *temp = head;

            while (temp != nullptr && temp->next->data != item) {
                temp = temp->next;
            }
            NewNode->next = temp->next;
            temp->next = NewNode;
        }
        else{
            cout << "no nodes";
        }
    }

    void insertlast(int newvalue){
        Node *newnode = new Node;
        newnode->data = newvalue;
        Node *temp = head;

        while (temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = nullptr;


    }

    void remove(int item){

        if(IsEmpty()){
             cout << "LL is empty";
        }
        Node*delptr;

        if(head->data == item){
            Node*delptr;
            delptr = head;
            head = head->next;
            delete delptr;
        }
        else{
            Node* prev;
            prev = NULL;
            delptr = head;
            while (delptr->data != item){
                prev = delptr;
                delptr = delptr->next;
            }
            prev->next = delptr->next;
            delete(delptr);



        }

    }




};


int main(){
    linkedlist list;
    int item;
    int stop;

//    if(list.IsEmpty()){
//        cout << " list is fucking empty";
//    }
//    else{
//        list.display();
//    }

//    cout <<"enter the amount of times u wanna go in the LL";
//    cin >> stop;


        cout << "enter item to put in LL";
       cin >> item;
        list.InsertNode(item);
        list.display();

    cout << "enter item to put in LL";
    cin >> item;
    list.InsertNode(item);
    list.display();

    cout << "enter item to put in LL";
    cin >> item;
    list.InsertNode(item);
    list.display();




    return 0;
}