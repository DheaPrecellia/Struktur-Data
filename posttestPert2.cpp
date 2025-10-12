#include <iostream>
using namespace std;

struct DataKTP {
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
};

class KTPHandler {
private:
    static const int jumlah_data = 7;
    DataKTP data[jumlah_data];

public:
    KTPHandler() {
        data[0] = {"7312042510720002", "ABDURRAUF", "CELLENGENGE, 25 - 10 - 1972", "Laki - Laki", "O",
                   "JL. MERDEKA NO.43", "001 / 004", "BILA", "LALABAT", "ISLAM", "KAWIN",
                   "PNS", "WNI", "SEUMUR HIDUP"};

        data[1] = {"7312040101010001", "ZULKIFLI", "SOPPENG, 01 - 01 - 1990", "Laki - Laki", "B",
                   "JL. POROS", "002 / 001", "SALOKARO", "DONRI-DONRI", "ISLAM", "KAWIN",
                   "GURU", "WNI", "SEUMUR HIDUP"};

        data[2] = {"7312040202020002", "BUDI", "WATANSOPPENG, 02 - 02 - 1992", "Laki - Laki", "A",
                   "JL. CENDRAWASIH", "003 / 002", "KAMPIRI", "LALABATA", "ISLAM", "BELUM KAWIN",
                   "MAHASISWA", "WNI", "SEUMUR HIDUP"};

        data[3] = {"7312040303030003", "SITI", "SALOKARO, 03 - 03 - 1995", "Perempuan", "AB",
                   "JL. SUDIRMAN", "004 / 003", "SALOKARO", "DONRI-DONRI", "ISLAM", "KAWIN",
                   "DOKTER", "WNI", "SEUMUR HIDUP"};

        data[4] = {"7312040404040004", "RAHMA", "BILA, 04 - 04 - 1998", "Perempuan", "O",
                   "JL. PELITA", "005 / 004", "BILA", "LALABATA", "ISLAM", "BELUM KAWIN",
                   "PERAWAT", "WNI", "SEUMUR HIDUP"};

        data[5] = {"7312040505050005", "ANDI", "MACCILE, 05 - 05 - 1994", "Laki - Laki", "B",
                   "JL. SERUNI", "006 / 005", "MACCILE", "LALABATA", "ISLAM", "KAWIN",
                   "PETANI", "WNI", "SEUMUR HIDUP"};

        data[6] = {"7312040606060006", "IRMA", "TAKKALALA, 06 - 06 - 1996", "Perempuan", "A",
                   "JL. KEMANG", "007 / 006", "TAKKALALA", "LILIRIAJA", "ISLAM", "KAWIN",
                   "WIRAUSAHA", "WNI", "SEUMUR HIDUP"};
    }

    void urutkanBerdasarkanNama() {
        for (int i = 0; i < jumlah_data - 1; i++) {
            for (int j = 0; j < jumlah_data - i - 1; j++) {
                if (data[j].nama > data[j + 1].nama) {
                    swap(data[j], data[j + 1]);
                }
            }
        }
    }

    void tampilkanSemua() const {
        for (int i = 0; i < jumlah_data; i++) {
            cout << "========== PROVINSI SULAWESI SELATAN ==========\n";
            cout << "============= KABUPATEN SOPPENG ===============\n";
            cout << "NIK                : " << data[i].nik << endl;
            cout << "Nama               : " << data[i].nama << endl;
            cout << "Tempat/Tgl Lahir   : " << data[i].tempat_tanggal_lahir << endl;
            cout << "Jenis Kelamin      : " << data[i].jenis_kelamin << endl;
            cout << "Gol. Darah         : " << data[i].gol_darah << endl;
            cout << "Alamat             : " << data[i].alamat << endl;
            cout << "RT/RW              : " << data[i].rt_rw << endl;
            cout << "Kel/Desa           : " << data[i].kel_desa << endl;
            cout << "Kecamatan          : " << data[i].kecamatan << endl;
            cout << "Agama              : " << data[i].agama << endl;
            cout << "Status Perkawinan  : " << data[i].status_perkawinan << endl;
            cout << "Pekerjaan          : " << data[i].pekerjaan << endl;
            cout << "Kewarganegaraan    : " << data[i].kewarganegaraan << endl;
            cout << "Berlaku Hingga     : " << data[i].berlaku_hingga << endl;
            cout << "================================================\n\n";
        }
    }
};

int main() {
    KTPHandler handler;

    cout << "\n>>> DATA SEBELUM DIURUTKAN BERDASARKAN NAMA <<<\n\n";
    handler.tampilkanSemua();

    handler.urutkanBerdasarkanNama();

    cout << "\n>>> DATA SETELAH DIURUTKAN BERDASARKAN NAMA <<<\n\n";
    handler.tampilkanSemua();

    return 0;
}

