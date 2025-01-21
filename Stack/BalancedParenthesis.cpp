#include <iostream>
using namespace std;

struct ListNode
{
    char value;
    ListNode* next;
};

class LinkedListStack
{
public:
    ListNode* head;

    LinkedListStack()
    {
        head = nullptr;
    }

    void addNode(char value)
    {
        ListNode* newNode = new ListNode{value, head};
        head = newNode;
    }

    char removeNode()
    {
        if (head == nullptr) {
            return '\0';
        }
        ListNode* temp = head;
        char value = head->value;
        head = head->next;
        delete temp;
        return value;
    }

    bool isEmpty()
    {
        return head==nullptr;
    }
};

bool checkBalancedParentheses(string expr) {
    LinkedListStack stack;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack.addNode(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty()) {
                return false;
            }
            char topChar = stack.removeNode();
            if ((ch == ')' && topChar != '(') || (ch == '}' && topChar != '{') || (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if (checkBalancedParentheses(expr))
        {
        cout << "Balanced\n";
    } else {
        cout << "Not Balanced\n";
    }

    return 0;
}

