#include <iostream>
using namespace std;

class KTP {
private:
    string nik;
    string nama;
    string tempat_tanggal_lahir;
    string jenis_kelamin;
    string gol_darah;
    string alamat;
    string rt_rw;
    string kel_desa;
    string kecamatan;
    string agama;
    string status_perkawinan;
    string pekerjaan;
    string kewarganegaraan;
    string berlaku_hingga;

public:
    KTP() {
        nik = "7312042510720002";
        nama = "ABDURRAUF, S.Pd, M.Pd";
        tempat_tanggal_lahir = "CELLENGENGE, 25 - 10 - 1972";
        jenis_kelamin = "Laki - Laki";
        gol_darah = "O";
        alamat = "JL. MERDEKA NO.43";
        rt_rw = "001 / 004";
        kel_desa = "BILA";
        kecamatan = "LALABAT";
        agama = "ISLAM";
        status_perkawinan = "KAWIN";
        pekerjaan = "PEGAWAI NEGERI SIPIL ( PNS)";
        kewarganegaraan = "WNI";
        berlaku_hingga = "SEUMUR HIDUP";
    }

    void tampilkan() const {
        cout << "========== PROVINSI SULAWESI SELATAN ==========" << endl;
        cout << "============= KABUPATEN SOPPENG ===============" << endl;
        cout << "NIK                : " << nik << endl;
        cout << "Nama               : " << nama << endl;
        cout << "Tempat/Tgl Lahir   : " << tempat_tanggal_lahir << endl;
        cout << "Jenis Kelamin      : " << jenis_kelamin << endl;
        cout << "Gol. Darah         : " << gol_darah << endl;
        cout << "Alamat             : " << alamat << endl;
        cout << "RT/RW              : " << rt_rw << endl;
        cout << "Kel/Desa           : " << kel_desa << endl;
        cout << "Kecamatan          : " << kecamatan << endl;
        cout << "Agama              : " << agama << endl;
        cout << "Status Perkawinan  : " << status_perkawinan << endl;
        cout << "Pekerjaan          : " << pekerjaan << endl;
        cout << "Kewarganegaraan    : " << kewarganegaraan << endl;
        cout << "Berlaku Hingga     : " << berlaku_hingga << endl;
    }
};

int main() {
    KTP ktp;
    ktp.tampilkan();

    return 0;
}

