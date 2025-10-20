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

