#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* addToEmpty(Node* last, int data) {
    if (last != nullptr) return last;
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = newNode;
    last = newNode;
    return last;
}

Node* addFront(Node* last, int data) {
    if (last == nullptr)
        return addToEmpty(last, data);
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
    return last;
}

Node* addEnd(Node* last, int data) {
    if (last == nullptr)
        return addToEmpty(last, data);
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
    return last;
}

Node* addAfter(Node* last, int data, int item) {
    if (last == nullptr) return nullptr;
    Node* p = last->next;
    do {
        if (p->data == item) {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = p->next;
            p->next = newNode;
            if (p == last) last = newNode;
            return last;
        }
        p = p->next;
    } while (p != last->next);
    cout << "Data " << item << " tidak ditemukan.\n";
    return last;
}

void deleteNode(Node** last, int key) {
    if (*last == nullptr) return;
    Node* temp = *last;
    Node* current = temp->next;
    if (temp->next == temp && temp->data == key) {
        delete temp;
        *last = nullptr;
        return;
    }
    if (temp->data == key) {
        while (current->next != *last)
            current = current->next;
        current->next = (*last)->next;
        delete *last;
        *last = current;
        return;
    }
    while (current->next != *last && current->next->data != key)
        current = current->next;
    if (current->next->data == key) {
        Node* d = current->next;
        current->next = d->next;
        delete d;
    }
}

void display(Node* last) {
    if (last == nullptr) {
        cout << "List kosong.\n";
        return;
    }
    Node* p = last->next;
    cout << "Isi Circular Linked List: ";
    do {
        cout << p->data << " -> ";
        p = p->next;
    } while (p != last->next);
    cout << "[kembali ke " << last->next->data << "]\n";
}

int main() {
    Node* last = nullptr;
    last = addToEmpty(last, 6);
    last = addEnd(last, 8);
    last = addFront(last, 2);
    last = addAfter(last, 10, 2);
    display(last);
    deleteNode(&last, 8);
    display(last);
    return 0;
}
