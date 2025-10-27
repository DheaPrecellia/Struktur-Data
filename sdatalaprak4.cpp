#include <iostream>
using namespace std;

// Struktur node
struct Node {
    int data;           // menyimpan nilai
    Node* next;      	// pointer ke node berikutnya
};

// pointer awal (head)
Node* head = NULL;

// Tambah node di depan
void tambahDepan(int value) {
    Node* newNode = new Node();    	// buat node baru
    newNode->data = value;
    newNode->next = head;       	// hubungkan ke head lama
    head = newNode;                	// jadikan node baru sebagai head
}

void tambahTengah(int value, int posisiSetelah) { //posisi data setelah..
    if (head == NULL) {
        cout << "List masih kosong! Tambahkan node terlebih dahulu.\n";
        return;
    }
    
    Node* newNode = new Node();
    Node* current = head;

    // Cari node dengan data yang di pilih
    while (current != NULL && current->data != posisiSetelah) {
        current = current->next;
    }
    
    // Jika yang data afterValue tidak ada
    if (current == NULL) {
        cout << "Data " << posisiSetelah << " tidak ditemukan dalam list!\n";
        return;
    }

    // Buat node baru
    newNode->data = value;
    newNode->next = current->next;
    current->next = newNode;
}

// Tambah node di belakang
void tambahBelakang(int value) {
    Node* newNode = new Node();
    newNode->data = value;		//data diisi value
    newNode->next = NULL;		//data next atau terakhir akan diisi NULL

    if (head == NULL) {
        head = newNode;       	// jika list kosong
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;     	// sambungkan di akhir
}

//Hapus node di depan
void hapusDepan() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }
    Node* temp = head;
    head = head->next;        	// pindahkan head ke node berikut
    delete temp;             	// hapus node lama
}

void hapusTengah(int targetValue) {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    Node* prev = head;
    while (prev->next != NULL && prev->next->data != targetValue)
        prev = prev->next;

    if (prev->next == NULL) {
        cout << "Data " << targetValue << " tidak ditemukan!\n";
        return;
    }

    Node* del = prev->next;
    prev->next = del->next;
    delete del;
}

// Hapus node di belakang
void hapusBelakang() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }
    if (head->next == NULL) { 	// hanya 1 elemen
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

// Tampilkan isi linked list
void traversal() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    Node* temp = head;
    cout << "Isi Linked List: ";
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Main program
int main() {
    tambahBelakang(10);
    traversal(); 
    
    tambahDepan(5);
    traversal(); 
    
    tambahBelakang(30);
    traversal(); 
    
    tambahTengah(20,10);
    traversal();   	// Output: 5 > 10 > 20 > 30 > NULL

    hapusDepan();
    traversal();   	// Output: 10 > 20 > 30 > NULL
    
    hapusTengah(20);
    traversal();	// Output: 10 > 30 > NULL

    hapusBelakang();
    traversal();   	// Output: 10 > NULL

    return 0;
}

