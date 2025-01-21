#include <iostream>
using namespace std;

struct MyStack{
    int *data;
    int index;
    int maxSize;

    MyStack(int size){
        data = new int[size];
        maxSize = size;
        index = -1;
    }

    bool isStackEmpty(){
        return index == -1;
    }

    bool isStackFull(){
        return index == maxSize - 1;
    }

    void pushData(int value){
        if(isStackFull()){
            cout << "Stack Overflow\n";
            return;
        }
        data[++index] = value;
    }

    void popData(){
        if(isStackEmpty()){
            cout << "Stack Underflow\n";
            return;
        }
        index--;
    }

    int peekTop(){
        if(isStackEmpty()){
            cout << "Stack is empty\n";
            return -1;
        }
        return data[index];
    }

    void displayStack(){
        if(isStackEmpty()){
            cout << "Stack is empty\n";
            return;
        }
        for(int i = 0; i <= index; i++) cout << data[i] << " ";
        cout << endl;
    }
};

int main(){
    int capacity, choice, value;
    cout << "Enter stack capacity: ";
    cin >> capacity;
    MyStack stack(capacity);

    do{
        cout << "\n1. Push Data\n2. Pop Data\n3. Peek Top Data\n4. Display Stack\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.pushData(value);
                break;
            case 2:
                stack.popData();
                break;
            case 3:
                cout << "Top element: " << stack.peekTop() << endl;
                break;
            case 4:
                stack.displayStack();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 5);

    return 0;
}

