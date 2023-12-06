#include<iostream>
using namespace std;

struct Process {
    int pid; // Process ID
    int bt; // Burst Time
};

// Function to find the waiting time for all processes
void findWaitingTime(Process proc[], int n, int wt[]) {
    wt[0] = 0;
    for (int i = 1; i < n ; i++ )
        wt[i] = proc[i-1].bt + wt[i-1];
}

// Function to calculate turn around time
void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n ; i++)
        tat[i] = proc[i].bt + wt[i];
}

// Function to calculate average time
void findavgTime(Process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);
    cout << "Processes  "<< " Burst time  "<< " Waiting time  " << " Turn around time\n";
    for (int i=0; i<n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << proc[i].pid << "\t\t" << proc[i].bt << "\t    " << wt[i] << "\t\t  " << tat[i] << endl;
    }
    cout << "Average waiting time = " << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    Process proc[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter process " << i+1 << " ID: ";
        cin >> proc[i].pid;
        cout << "Enter process " << i+1 << " burst time: ";
        cin >> proc[i].bt;
    }
    findavgTime(proc, n);
    return 0;
}
