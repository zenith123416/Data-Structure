#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        value = val;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() {
        root = nullptr;
    }

    void insertValue(int val) {
        root = insertNode(root, val);
    }

    void removeValue(int val) {
        root = removeNode(root, val);
    }

    int getMaximum() {
        TreeNode* maxNode = findMaximum(root);
        if (maxNode) return maxNode->value;
        return -1;
    }

    int getMinimum() {
        TreeNode* minNode = findMinimum(root);
        if (minNode) return minNode->value;
        return -1;
    }

    void inOrderTraversal() {
        inOrder(root);
        cout << endl;
    }

    void preOrderTraversal() {
        preOrder(root);
        cout << endl;
    }

    void postOrderTraversal() {
        postOrder(root);
        cout << endl;
    }

private:
    TreeNode* insertNode(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }
        if (val < node->value) {
            node->left = insertNode(node->left, val);
        } else {
            node->right = insertNode(node->right, val);
        }
        return node;
    }

    TreeNode* removeNode(TreeNode* node, int val) {
        if (node == nullptr) return node;

        if (val < node->value) {
            node->left = removeNode(node->left, val);
        } else if (val > node->value) {
            node->right = removeNode(node->right, val);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = findMinimum(node->right);
            node->value = temp->value;
            node->right = removeNode(node->right, temp->value);
        }
        return node;
    }

    TreeNode* findMinimum(TreeNode* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    TreeNode* findMaximum(TreeNode* node) {
        while (node && node->right) {
            node = node->right;
        }
        return node;
    }

    void inOrder(TreeNode* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->value << " ";
        inOrder(node->right);
    }

    void preOrder(TreeNode* node) {
        if (node == nullptr) return;
        cout << node->value << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(TreeNode* node) {
        if (node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->value << " ";
    }
};

int main() {
    BinaryTree tree;
    int option, value;

    do {
        cout << "\n1.Insert Value\n2.Remove Value\n3.Get Maximum\n4.Get Minimum\n5.In-order Traversal\n6.Pre-order Traversal\n7.Post-order Traversal\n8.Exit\n";
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insertValue(value);
                break;
            case 2:
                cout << "Enter value to remove: ";
                cin >> value;
                tree.removeValue(value);
                break;
            case 3:
                cout << "Maximum value: " << tree.getMaximum() << endl;
                break;
            case 4:
                cout << "Minimum value: " << tree.getMinimum() << endl;
                break;
            case 5:
                cout << "In-order Traversal: ";
                tree.inOrderTraversal();
                break;
            case 6:
                cout << "Pre-order Traversal: ";
                tree.preOrderTraversal();
                break;
            case 7:
                cout << "Post-order Traversal: ";
                tree.postOrderTraversal();
                break;
            case 8:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (option != 8);

    return 0;
}

