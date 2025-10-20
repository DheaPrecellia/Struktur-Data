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

