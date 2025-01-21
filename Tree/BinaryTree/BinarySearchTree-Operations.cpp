#include <iostream>
using namespace std;

struct TreeElement {
    int value;
    TreeElement* leftChild;
    TreeElement* rightChild;
};

class BinaryTreeOperations {
public:
    TreeElement* rootNode;

    BinaryTreeOperations() {
        rootNode = nullptr;
    }

    TreeElement* insertElement(TreeElement* node, int value) {
        if (node == nullptr) {
            node = new TreeElement{value, nullptr, nullptr};
            return node;
        }
        if (value < node->value)
            node->leftChild = insertElement(node->leftChild, value);
        else
            node->rightChild = insertElement(node->rightChild, value);
        return node;
    }

    void insert(int value) {
        rootNode = insertElement(rootNode, value);
    }

    void inOrderTraversal(TreeElement* node) {
        if (node == nullptr)
            return;
        inOrderTraversal(node->leftChild);
        cout << node->value << " ";
        inOrderTraversal(node->rightChild);
    }

    void preOrderTraversal(TreeElement* node) {
        if (node == nullptr)
            return;
        cout << node->value << " ";
        preOrderTraversal(node->leftChild);
        preOrderTraversal(node->rightChild);
    }

    void postOrderTraversal(TreeElement* node) {
        if (node == nullptr)
            return;
        postOrderTraversal(node->leftChild);
        postOrderTraversal(node->rightChild);
        cout << node->value << " ";
    }

    void searchForElement(TreeElement* node, int value) {
        if (node == nullptr) {
            cout << "Element not found in tree.\n";
            return;
        }
        if (node->value == value) {
            cout << "Element " << value << " found in tree.\n";
            return;
        }
        if (value < node->value)
            searchForElement(node->leftChild, value);
        else
            searchForElement(node->rightChild, value);
    }

    TreeElement* removeElement(TreeElement* node, int value) {
        if (node == nullptr)
            return nullptr;
        if (value < node->value)
            node->leftChild = removeElement(node->leftChild, value);
        else if (value > node->value)
            node->rightChild = removeElement(node->rightChild, value);
        else {
            if (node->leftChild == nullptr) {
                TreeElement* temp = node->rightChild;
                delete node;
                return temp;
            } else if (node->rightChild == nullptr) {
                TreeElement* temp = node->leftChild;
                delete node;
                return temp;
            }
            TreeElement* temp = findMinNode(node->rightChild);
            node->value = temp->value;
            node->rightChild = removeElement(node->rightChild, temp->value);
        }
        return node;
    }

    TreeElement* findMinNode(TreeElement* node) {
        while (node && node->leftChild)
            node = node->leftChild;
        return node;
    }

    void deleteElement(int value) {
        rootNode = removeElement(rootNode, value);
    }

    void displayInOrder() {
        inOrderTraversal(rootNode);
        cout << endl;
    }

    void displayPreOrder() {
        preOrderTraversal(rootNode);
        cout << endl;
    }

    void displayPostOrder() {
        postOrderTraversal(rootNode);
        cout << endl;
    }
};

int main() {
    BinaryTreeOperations tree;
    int choice, value;

    do {
        cout << "\n1.Insert Element\n2.In-order Traversal\n3.Pre-order Traversal\n4.Post-order Traversal\n5.Search Element\n6.Remove Element\n7.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "In-order Traversal: ";
                tree.displayInOrder();
                break;
            case 3:
                cout << "Pre-order Traversal: ";
                tree.displayPreOrder();
                break;
            case 4:
                cout << "Post-order Traversal: ";
                tree.displayPostOrder();
                break;
            case 5:
                cout << "Enter element to search: ";
                cin >> value;
                tree.searchForElement(tree.rootNode, value);
                break;
            case 6:
                cout << "Enter element to remove: ";
                cin >> value;
                tree.deleteElement(value);
                break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 7);

    return 0;
}

