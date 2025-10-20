#include <iostream>
using namespace std;

#define MAKS 10

class Array1D {
public:
    char A[MAKS] = {'A', 'B', 'C', 'D', 'F', 'G', 'H', 'I', 'J'};


    void cetak() {
        for (int i = 0; i < MAKS; i++)
            cout << A[i] << " ";
        cout << endl;
    }

    void geserKiri() {
        char temp = A[0];
        for (int i = 0; i < MAKS - 1; i++)
            A[i] = A[i + 1];
        A[MAKS - 1] = temp;
    }

    void geserKanan() {
        char temp = A[MAKS - 1];
        for (int i = MAKS - 1; i > 0; i--)
            A[i] = A[i - 1];
        A[0] = temp;
    }
};

int main() {
    Array1D x;

    //x.input();
    cout << "Isi array saat ini: ";
    x.cetak();

	x.geserKanan();
    cout << "Isi array setelah digeser ke kanan: ";
    x.cetak();
    
    x.geserKiri();
    cout << "Isi array setelah digeser ke kiri: ";
    x.cetak();


    return 0;
}
