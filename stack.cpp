#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Push - O(1)
    void push(int value) {
        if (top == 99) {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top] = value;
        cout << "Inserted\n";
    }

    // Pop - O(1)
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }

        cout << "Removed: " << arr[top--] << endl;
    }

    // Search - O(n)
    void search(int value) {
        for (int i = 0; i <= top; i++) {
            if (arr[i] == value) {
                cout << "Found\n";
                return;
            }
        }

        cout << "Not Found\n";
    }

    // Display - O(n)
    void display() {
        if (top == -1) {
            cout << "Stack Empty\n";
            return;
        }

        cout << "Stack Elements:\n";

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                s.search(value);
                break;

            case 4:
                s.display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while(choice != 5);

    return 0;
}