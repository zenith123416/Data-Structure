#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    void add(int val) {
        root = addNode(root, val);
    }

    void inTraversal() {
        inOrder(root);
        cout << endl;
    }

    void preTraversal() {
        preOrder(root);
        cout << endl;
    }

    void postTraversal() {
        postOrder(root);
        cout << endl;
    }

private:
    Node* addNode(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = addNode(node->left, val);
        } else {
            node->right = addNode(node->right, val);
        }
        return node;
    }

    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void preOrder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node* node) {
        if (node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
};

int main() {
    Tree t;
    int option, value;

    do {
        cout << "\n1.Add Node\n2.In-order Traversal\n3.Pre-order Traversal\n4.Post-order Traversal\n5.Exit\n";
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter value to add: ";
                cin >> value;
                t.add(value);
                break;
            case 2:
                cout << "In-order Traversal: ";
                t.inTraversal();
                break;
            case 3:
                cout << "Pre-order Traversal: ";
                t.preTraversal();
                break;
            case 4:
                cout << "Post-order Traversal: ";
                t.postTraversal();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (option != 5);

    return 0;
}
