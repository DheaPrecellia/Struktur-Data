FCFS
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int bt[20], wt[20], tat[20], n;
    float wtavg = 0, tatavg = 0;

    cout << "\n=== PROGRAM PENJADWALAN PROSES FCFS ===\n";
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    // Input burst time tiap proses
    for (int i = 0; i < n; i++) {
        cout << "Masukkan Burst Time untuk Proses P" << i + 1 << ": ";
        cin >> bt[i];
    }

    // Hitung waktu tunggu dan turnaround
    wt[0] = 0;
    tat[0] = bt[0];
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
    }

    // Hitung total dan rata-rata
    for (int i = 0; i < n; i++) {
        wtavg += wt[i];
        tatavg += tat[i];
    }

    wtavg /= n;
    tatavg /= n;

    // Tampilkan hasil
    cout << "\n============================================================\n";
    cout << "  PROSES  |  BURST TIME  |  WAITING TIME  |  TURNAROUND TIME\n";
    cout << "------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << "   P" << setw(6) << left << i + 1
             << " |     " << setw(9) << left << bt[i]
             << " |      " << setw(10) << left << wt[i]
             << " |       " << setw(10) << left << tat[i] << "\n";
    }
    cout << "------------------------------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Rata-rata Waiting Time   = " << wtavg << "\n";
    cout << "Rata-rata Turnaround Time = " << tatavg << "\n";
    cout << "============================================================\n";

    return 0;
}

SJF
//SJF
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int p[20], bt[20], wt[20], tat[20];
    int n, temp;
    float wtavg = 0, tatavg = 0;

    cout << "\n=== PROGRAM PENJADWALAN PROSES - SJF (Shortest Job First) ===\n";
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    // Input Burst Time
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        cout << "Masukkan Burst Time untuk Proses P" << i + 1 << ": ";
        cin >> bt[i];
    }

    // Sorting berdasarkan burst time (SJF)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Hitung waktu tunggu dan turnaround time
    wt[0] = 0;
    tat[0] = bt[0];
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
    }

    // Hitung rata-rata
    for (int i = 0; i < n; i++) {
        wtavg += wt[i];
        tatavg += tat[i];
    }
    wtavg /= n;
    tatavg /= n;

    // Tampilkan hasil
    cout << "\n=============================================================\n";
    cout << "  PROSES  |  BURST TIME  |  WAITING TIME  |  TURNAROUND TIME\n";
    cout << "-------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << "   P" << setw(6) << left << p[i]
             << " |     " << setw(9) << bt[i]
             << " |      " << setw(10) << wt[i]
             << " |       " << setw(10) << tat[i] << endl;
    }
    cout << "-------------------------------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Rata-rata Waiting Time    = " << wtavg << endl;
    cout << "Rata-rata Turnaround Time = " << tatavg << endl;
    cout << "=============================================================\n";

    return 0;
}

ROUND ROBIN
//RoundRobin

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int i, j, n, bt[10], wt[10], tat[10], ct[10], max, t;
    float awt = 0, atat = 0, temp = 0;

    cout << "=== PROGRAM PENJADWALAN PROSES ROUND ROBIN ===\n";
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "Masukkan Burst Time untuk Proses " << i + 1 << ": ";
        cin >> bt[i];
        ct[i] = bt[i]; // simpan burst time asli
    }

    cout << "\nMasukkan besar Time Slice: ";
    cin >> t;

    // Cari burst time maksimum
    max = bt[0];
    for (i = 1; i < n; i++) {
        if (max < bt[i])
            max = bt[i];
    }

    // Proses Round Robin
    for (j = 0; j < (max / t) + 1; j++) {
        for (i = 0; i < n; i++) {
            if (bt[i] != 0) {
                if (bt[i] <= t) {
                    temp += bt[i];
                    tat[i] = temp;  // turnaround time
                    bt[i] = 0;
                } else {
                    bt[i] -= t;
                    temp += t;
                }
            }
        }
    }

    // Hitung waktu tunggu dan rata-rata
    for (i = 0; i < n; i++) {
        wt[i] = tat[i] - ct[i];
        awt += wt[i];
        atat += tat[i];
    }

    awt /= n;
    atat /= n;

    // Output hasil
    cout << "\n============================================================\n";
    cout << "  PROSES  |  BURST TIME  |  WAITING TIME  |  TURNAROUND TIME\n";
    cout << "------------------------------------------------------------\n";
    for (i = 0; i < n; i++) {
        cout << "   P" << setw(6) << left << i + 1
             << " |     " << setw(9) << ct[i]
             << " |      " << setw(10) << wt[i]
             << " |       " << setw(10) << tat[i] << endl;
    }
    cout << "------------------------------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Rata-rata Waiting Time    = " << awt << endl;
    cout << "Rata-rata Turnaround Time = " << atat << endl;
    cout << "============================================================\n";

    return 0;
}

//Priority

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int p[20], bt[20], pri[20], wt[20], tat[20];
    int i, k, n, temp;
    float wtavg = 0, tatavg = 0;

    cout << "=== PROGRAM PENJADWALAN PROSES - PRIORITY SCHEDULING ===\n";
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        cout << "Masukkan Burst Time dan Prioritas untuk Proses P" << i + 1 << " (BT PR): ";
        cin >> bt[i] >> pri[i];
    }

    // Pengurutan berdasarkan prioritas (semakin kecil = semakin tinggi)
    for (i = 0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
            if (pri[i] > pri[k]) {
                temp = p[i]; p[i] = p[k]; p[k] = temp;
                temp = bt[i]; bt[i] = bt[k]; bt[k] = temp;
                temp = pri[i]; pri[i] = pri[k]; pri[k] = temp;
            }
        }
    }

    // Perhitungan waktu tunggu dan turnaround
    wt[0] = 0;
    tat[0] = bt[0];
    wtavg = 0;
    tatavg = bt[0];

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    // Output hasil
    cout << "\n===============================================================\n";
    cout << " PROSES  | PRIORITAS | BURST TIME | WAITING TIME | TURNAROUND TIME\n";


