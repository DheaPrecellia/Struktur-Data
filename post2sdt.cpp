#include<iostream>
using namespace std;
#define MAKS 5

class Array1D {
public:
	char A[MAKS];
	
	Array1D(){
		for(int i = 0; i< MAKS; i++)
		A[i] = '0';
	}
	
	void input(){
		char nilai;
		A [0] = 'A';
		A [1] = 'B';
		A [2] = 'C';
		A [3] = 'D';
		A [4] = 'E';
	}
	
	void cetak(){
		for(int i = 0; i < MAKS; i++)
		cout <<A[i]<< " ";
		cout<<endl;
	}
	
	void geserKiri(){
		char temp = A[0];
		for(int i = 0; i < MAKS - 1; i++)
			A[i] = A [i + 1];
			A[MAKS - 1] = temp;
	}
	
	void geserKanan(){
		char temp = A[MAKS - 1];
		for(int i = MAKS - 1; i > 0; i--)
			A[i] = A [i - 1];
			A[0] = temp;
	}

};

int main(){
	Array1D x;
	
	cout<<"Array masih kosong: ";
	x.cetak();
	
	x.input();
	cout<<"Isi Array setelah input statis: ";
	x.cetak();
	
	x.geserKiri();
	cout<<"Isi Array setelah digeser ke kiri: ";
	x.cetak();
	
	x.geserKanan();
	cout<<"Isi Array setelah digeser ke kiri: ";
	x.cetak();
	
}
