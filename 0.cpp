#include <iostream>
#include <string>
using namespace std;

class NilaiMahasiswa {
private:
    int jumlah;
    struct Mahasiswa {
        string nama;
        string nim;
        float nilai;
    };
    Mahasiswa* mahasiswa; // pointer untuk array dinamis mahasiswa

public: 
    void inputNilai() {
        cout << "Masukkan jumlah mahasiswa: ";
        cin >> jumlah;

        // Alokasi memori dinamis untuk array mahasiswa
        mahasiswa = new Mahasiswa[jumlah];

        cout << "\n==== Input Data Mahasiswa ====\n";
        for (int i = 0; i < jumlah; i++) {
            cout << "Mahasiswa ke-" << i + 1 << endl;
            cout << "Nama: ";
            cin.ignore();  // Untuk membersihkan buffer sebelum input string
            getline(cin, mahasiswa[i].nama);
            cout << "Masukkan NIM Anda: ";
            cin >> mahasiswa[i].nim;
            cout << "Nilai: ";
            cin >> mahasiswa[i].nilai;
            cout << endl;
        }

        // Menampilkan daftar mahasiswa dan nilai mereka
        cout << "\n==== Daftar Nilai Mahasiswa ====\n";
        float total = 0;
        float nilaiTertinggi = mahasiswa[0].nilai;
        float nilaiTerendah = mahasiswa[0].nilai;
        int jumlahLulus = 0;
        int jumlahTidakLulus = 0;

        for (int i = 0; i < jumlah; i++) {
            cout << "Mahasiswa ke-" << i + 1 << " - Nama: " << mahasiswa[i].nama 
                 << ", NIM: " << mahasiswa[i].nim << ", Nilai: " << mahasiswa[i].nilai << endl;

            total += mahasiswa[i].nilai;

            // Menentukan nilai tertinggi dan terendah
            if (mahasiswa[i].nilai > nilaiTertinggi) {
                nilaiTertinggi = mahasiswa[i].nilai;
            }
            if (mahasiswa[i].nilai < nilaiTerendah) {
                nilaiTerendah = mahasiswa[i].nilai;
            }

            // Menghitung jumlah mahasiswa lulus dan tidak lulus
            if (mahasiswa[i].nilai >= 60) {
                jumlahLulus++;
            } else {
                jumlahTidakLulus++;
            }
        }

        cout << "\nRata-rata nilai: " << total / jumlah << endl;
        cout << "Nilai Tertinggi: " << nilaiTertinggi << endl;
        cout << "Nilai Terendah: " << nilaiTerendah << endl;
        cout << "Jumlah Mahasiswa Lulus: " << jumlahLulus << endl;
        cout << "Jumlah Mahasiswa Tidak Lulus: " << jumlahTidakLulus << endl;

        // Hapus memori dinamis setelah digunakan
        delete[] mahasiswa;
    }
};

int main() {
    NilaiMahasiswa data;
    data.inputNilai();
    return 0;
}

