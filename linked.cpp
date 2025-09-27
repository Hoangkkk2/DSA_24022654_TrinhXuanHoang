#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// O(n)
int getNodeAt(Node* head, int index) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (count == index) return temp->data;
        count++;
        temp = temp->next;
    }
    cout << "Vi tri vuot qua do dai danh sach!\n";
    return -1;
}

// O(1)
void insertFront(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// O(n)
void insertAt(Node*& head, int value, int index) {
    if (index == 0) {
        insertFront(head, value);
        return;
    }
    Node* temp = head;
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Vi tri chen khong hop le!\n";
        return;
    }
    Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

// O(1)
void deleteFront(Node*& head) {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// O(n)
void deleteEnd(Node*& head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

// O(n)
void deleteAt(Node*& head, int index) {
    if (head == NULL) return;
    if (index == 0) {
        deleteFront(head);
        return;
    }
    Node* temp = head;
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        cout << "Vi tri xoa khong hop le!\n";
        return;
    }
    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

// O(n)
void printForward(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// O(n)
void printBackward(Node* head) {
    if (head == NULL) return;
    printBackward(head->next);
    cout << head->data << " <- ";
}

// O(n)
void freeList(Node*& head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = NULL;
    int choice, value, index;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Truy cap phan tu\n";
        cout << "2. Chen vao dau\n";
        cout << "3. Chen vao vi tri i\n";
        cout << "4. Xoa dau\n";
        cout << "5. Xoa cuoi\n";
        cout << "6. Xoa vi tri i\n";
        cout << "7. Duyet xuoi\n";
        cout << "8. Duyet nguoc\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap vi tri can truy cap: ";
                cin >> index;
                value = getNodeAt(head, index);
                if (value != -1) {
                    cout << "Gia tri: " << value << endl;
                }
                break;
            case 2:
                cout << "Nhap gia tri: ";
                cin >> value;
                insertFront(head, value);
                break;
            case 3:
                cout << "Nhap gia tri: ";
                cin >> value;
                cout << "Nhap vi tri: ";
                cin >> index;
                insertAt(head, value, index);
                break;
            case 4:
                deleteFront(head);
                break;
            case 5:
                deleteEnd(head);
                break;
            case 6:
                cout << "Nhap vi tri can xoa: ";
                cin >> index;
                deleteAt(head, index);
                break;
            case 7:
                printForward(head);
                break;
            case 8:
                printBackward(head);
                cout << "NULL\n";
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);

    freeList(head);
    return 0;
}

