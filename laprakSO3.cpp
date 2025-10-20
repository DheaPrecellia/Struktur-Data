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

