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


