#include <iostream>
using namespace std;

int main() {
    int n, i;
    cout << "Enter the number of processes: ";
    cin >> n;
    
    int processes[n], burstTime[n], waitingTime[n], turnAroundTime[n];

    cout << "Enter the burst time for each process:\n";
    for (i = 0; i < n; i++) {
        processes[i] = i + 1;
        cout << "Process " << i + 1 << ": ";
        cin >> burstTime[i];
    }

    waitingTime[0] = 0;
    for (i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }

    for (i = 0; i < n; i++) {
        turnAroundTime[i] = waitingTime[i] + burstTime[i];
    }

    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (i = 0; i < n; i++) {
        cout << "P" << processes[i] << "\t\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnAroundTime[i] << endl;
    }

    return 0;
}

