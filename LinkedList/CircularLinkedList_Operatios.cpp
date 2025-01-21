#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void printList(Node* head){
    if(!head) return;
    Node* temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);
    cout << endl;
}

Node* insertAtBeginning(Node* head, int value){
    Node* newNode = new Node{value, nullptr};
    if(!head){
        newNode->next = newNode;
        return newNode;
    }
    Node* temp = head;
    while(temp->next != head) temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
    return newNode;
}

Node* insertAtEnd(Node* head, int value){
    Node* newNode = new Node{value, nullptr};
    if(!head){
        newNode->next = newNode;
        return newNode;
    }
    Node* temp = head;
    while(temp->next != head) temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
    return head;
}

Node* deleteNode(Node* head, int value){
    if(!head) return nullptr;
    Node* temp = head;
    if(head->data == value){
        if(head->next == head){
            delete head;
            return nullptr;
        }
        while(temp->next != head) temp = temp->next;
        Node* toDelete = head;
        head = head->next;
        temp->next = head;
        delete toDelete;
        return head;
    }
    while(temp->next != head && temp->next->data != value) temp = temp->next;
    if(temp->next){
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
    return head;
}

bool searchNode(Node* head, int value){
    if(!head) return false;
    Node* temp = head;
    do{
        if(temp->data == value) return true;   //code by ZenithCSE1-DontCopy//
        temp = temp->next;
    }while(temp != head);
    return false;
}

int main(){
    Node* head = nullptr;
    int choice, value;
    do{
        cout << "\n1.Print List\n2.Insert at Beginning\n3.Insert at End\n4.Delete a Node\n5.Search for a Value\n6.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                head = new Node{1, nullptr};
                head->next = head;
                cout<<"List created: ";
                printList(head);
                break;
            case 2:
                cout <<"Enter value to insert at the beginning: ";
                cin >> value;
                head = insertAtBeginning(head, value);
                cout << "Updated list: ";
                printList(head);
                break;
            case 3:
                cout << "Enter value to insert at the end: ";
                cin >> value;
                head = insertAtEnd(head, value);
                cout << "Updated list: ";
                printList(head);
                break;
            case 4:
                cout <<"Enter value to delete: ";
                cin>>value;
                head = deleteNode(head, value);
                cout <<"Updated list: ";
                printList(head);
                break;
            case 5:
                cout <<"Enter value to search for: ";
                cin >> value;
                if(searchNode(head, value)){
                    cout <<"Value " << value << " found in the list." << endl;
                } else {
                    cout <<"Value " << value << " not found." << endl;
                }
                break;
            case 6:
                cout <<"Exiting program." << endl;
                break;
            default:
                cout <<"Invalid choice. Please try again." << endl;
        }
    } while(choice != 6);
    return 0;
}

