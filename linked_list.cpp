#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Insert at end - O(n)
    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Delete node - O(n)
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted\n";
            return;
        }

        Node* curr = head;

        while (curr->next != NULL && curr->next->data != value) {
            curr = curr->next;
        }

        if (curr->next == NULL) {
            cout << "Value not found\n";
            return;
        }

        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;

        cout << "Node deleted\n";
    }

    // Search - O(n)
    void search(int value) {
        Node* temp = head;
        int position = 1;

        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Found at position " << position << endl;
                return;
            }

            temp = temp->next;
            position++;
        }

        cout << "Not Found\n";
    }

    // Display - O(n)
    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\n--- LINKED LIST MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insert(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;

            case 4:
                list.display();
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