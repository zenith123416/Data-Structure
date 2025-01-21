#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void printList(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = new Node{value, head};
    return newNode;
}

Node* insertAtEnd(Node* head, int value) {
    if(!head) return new Node{value, nullptr};
    Node* temp = head;
    while(temp->next) temp = temp->next;
    temp->next = new Node{value, nullptr};
    return head;
}

Node* deleteNode(Node* head, int value) {
    if(!head) return nullptr;
    if(head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    while(temp->next && temp->next->data != value) temp = temp->next;
    if(temp->next) {
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }
    return head;
}

bool searchNode(Node* head, int value) {
    while(head) {
        if(head->data == value) return true;
        head = head->next;
    }
    return false;
}

int main() {
    Node* head = nullptr;
    int choice, value;

    do {
        cout << "\n1. Create and Print List\n2. Insert at Beginning\n3. Insert at End\n4. Delete a Node\n5. Search for a Value\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                head = new Node{1, nullptr};
                head->next = new Node{2, nullptr};
                head->next->next = new Node{3, nullptr};
                cout << "List created: ";
                printList(head);
                break;
            case 2:
                cout << "Enter value to insert at the beginning: ";
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
                cout << "Enter value to delete: ";
                cin >> value;
                head = deleteNode(head, value);
                cout << "Updated list: ";
                printList(head);
                break;
            case 5:
                cout << "Enter value to search for: ";
                cin >> value;
                if(searchNode(head, value)) {
                    cout << "Value " << value << " found in the list." << endl;
                } else {
                    cout << "Value " << value << " not found." << endl;
                }
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 6);

    return 0;
}
